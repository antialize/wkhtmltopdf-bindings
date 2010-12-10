<?php

	// Automated configuration. Modify these if they fail. (they shouldn't ;) )
	$GLOBALS['WKPDF_BASE_PATH']=str_replace(str_replace('\\','/',getcwd().'/'),'',dirname(str_replace('\\','/',__FILE__))).'/';
	$GLOBALS['WKPDF_BASE_SITE']='http://'.$_SERVER['SERVER_NAME'].'/';

	/**
	 * @author Christian Sciberras
	 * @see <a href="http://code.google.com/p/wkhtmltopdf/">http://code.google.com/p/wkhtmltopdf/</a>
	 * @copyright 2010 Christian Sciberras / Keen Advertising / Covac Software.
	 * @license None. There are no restrictions on use, however keep copyright intact.
	 *   Modification is allowed, keep track of modifications below in this comment block.
	 * @example
	 *   <font color="#008800"><i>//-- Create sample PDF and embed in browser. --//</i></font><br>
	 *   <br>
	 *   <font color="#008800"><i>// Include WKPDF class.</i></font><br>
	 *   <font color="#0000FF">require_once</font>(<font color="#FF0000">'wkhtmltopdf/wkhtmltopdf.php'</font>);<br>
	 *   <font color="#008800"><i>// Create PDF object.</i></font><br>
	 *   <font color="#EE00EE">$pdf</font>=new <b>WKPDF</b>();<br>
	 *   <font color="#008800"><i>// Set PDF's HTML</i></font><br>
	 *   <font color="#EE00EE">$pdf</font>-><font color="#0000FF">set_html</font>(<font color="#FF0000">'Hello &lt;b&gt;Mars&lt;/b&gt;!'</font>);<br>
	 *   <font color="#008800"><i>// Convert HTML to PDF</i></font><br>
	 *   <font color="#EE00EE">$pdf</font>-><font color="#0000FF">render</font>();<br>
	 *   <font color="#008800"><i>// Output PDF. The file name is suggested to the browser.</i></font><br>
	 *   <font color="#EE00EE">$pdf</font>-><font color="#0000FF">output</font>(<b>WKPDF</b>::<font color="#EE00EE">$PDF_EMBEDDED</font>,<font color="#FF0000">'sample.pdf'</font>);<br>
	 * @version
	 *   0.6 Anand, Chris - Added support for custom arguments (the functions args_add, args_remove and args_clear).
	 *   0.5 Pat Brooks - Identifying certain return error codes.
	 *   0.4 Adam, Pierino, Chris - Protected fields, IP instead domain, pages from multiple sources.<br>
	 *   0.3 Chris - CPU and CPU vendor detection to suggest proper executable.<br>
	 *   0.2 Chris - Better error handlng (via exceptions).<br>
	 *   0.1 Chris - Variable paths fixes.<br>
	 *   0.0 Chris - Created class.<br>
	 * <font color="#FF0000"><b>IMPORTANT: Make sure that there is a folder in %LIBRARY_PATH%/tmp that is writable!</b></font>
	 * <br><br>
	 * <b>Features/Bugs/Contact</b><br>
	 * Found a bug? Want a modification? Contact me at <a href="mailto:uuf6429@gmail.com">uuf6429@gmail.com</a> or <a href="mailto:contact@covac-software.com">contact@covac-software.com</a>...
	 */
	class WKPDF {
		/**
		 * protected use variables.
		 */
		protected $cmd='';
		protected $tmp='';
		protected $pdf='';
		protected $status='';
		protected $orient='Portrait';
		protected $size='A4';
		protected $toc=false;
		protected $copies=1;
		protected $grayscale=false;
		protected $title='';
		protected $args=array();
		protected static $_cpu='';
		protected static $_os='';
		protected static $_cmd='';
		/**
		 * Advanced execution routine.
		 * @param string $cmd The command to execute.
		 * @param string $input Any input not in arguments.
		 * @return array An array of execution data; stdout, stderr and return "error" code.
		 */
		protected static function _pipeExec($cmd,$input=''){
			$proc=@proc_open($cmd,array(0=>array('pipe','r'),1=>array('pipe','w'),2=>array('pipe','w')),$pipes,null,null,array('suppress_errors'=>true));
			if(!$proc)return array('stdout'=>'','stderr'=>'CreateProcess failed.','return'=>1);
			fwrite($pipes[0],$input);
			fclose($pipes[0]);
			$stdout=stream_get_contents($pipes[1]); // max execusion time exceeded issue
			fclose($pipes[1]);
			$stderr=stream_get_contents($pipes[2]);
			fclose($pipes[2]);
			$rtn=proc_close($proc);
			return array(
					'stdout'=>$stdout,
					'stderr'=>$stderr,
					'return'=>(int)$rtn
				);
		}
		/**
		 * Function that attempts to return the kind of platform.
		 * @return string OS kind ('win', 'lin' or 'osx').
		 */
		protected static function _getOS(){
			if(self::$_os==''){
				if(stristr(PHP_OS,'WIN') && !stristr(PHP_OS,'DAR'))	self::$_os='win';
				elseif(`uname | grep -i linux`!='')					self::$_os='lin';
				elseif(`uname | grep -i darwin`!='')				self::$_os='osx';
				else throw new Exception('WKPDF couldn\'t determine OS.');
			}
			return self::$_os;
		}
		/**
		 * Function that attempts to return the kind of CPU.
		 * @return string CPU kind ('amd', 'intel' or 'ppc').
		 */
		protected static function _getCPU(){
			if(self::$_cpu==''){
				switch(self::_getOS()){
					case 'lin':
// TODO: use uname -m or -a, by the way, this is about 32bit vs 64bit not amd vs intel!
						if(`grep -i amd /proc/cpuinfo`!='')			self::$_cpu='amd';
						elseif(`grep -i intel /proc/cpuinfo`!='')	self::$_cpu='intel';
						break;
					case 'osx':
// TODO: use uname -m or -a
						if(`machine | grep -i ppc`!='')				self::$_cpu='ppc';
						// TODO: I don't like this check on a single character
						elseif(`machine | grep -i i`!='')			self::$_cpu='intel';
						break;
					case 'win':
						$cpu=strtolower(getenv('PROCESSOR_IDENTIFIER'));
						if(strpos($cpu,'intel')!==false)self::$_cpu='intel';
						if(strpos($cpu,'amd')!==false)self::$_cpu='amd';
						break;
					default:
						throw new Exception('WKPDF CPU detection on '.self::_getOS().' OS not supported.');
						break;
				}
				if(self::$_cpu=='')throw new Exception('WKPDF couldn\'t determine CPU ('.self::_getOS().' OS).');
			}
			return self::$_cpu;
		}
		/**
		 * Function that attempts to return the correct executable path.
		 * @return string WKHTMLTOPDF path.
		 */
		protected static function _getCMD(){
			if(self::$_cmd==''){
				// the end filename is in the form of "(%PATH%)wkhtmltopdf[-(win|osx|lin)-(amd64|i386|ppc)][.exe]"
				self::$_cmd=$GLOBALS['WKPDF_BASE_PATH'];
				self::$_cmd.=self::_getOS()=='win' ? 'wkhtmltopdf.exe' : 'wkhtmltopdf-'.self::_getOS().'-'.self::_getCPU();
			}
			switch(self::_getOS()){
				case 'win': // checks file existence (permissions on windows isn't much of a problem)
					// for windows, the command is "exists %filename%" ... try it out?
					break;
				case 'lin': case 'osx': // checks file existence and permissions using LS
					$exists=self::_pipeExec('test -f "'.self::$_cmd.'"');
					if($exists['return']>0)
						throw new Exception('WKPDF executable couldn\'t be found ("'.htmlspecialchars(self::$_cmd).'").');
					$exists=explode(' ',str_replace('  ',' ',str_replace('	',' ',$exists['stdout']))); // perms, unused, group, user, ...
					if(count($exists)>1) // "test" command ran, keep testing settings, otherwise just ignore tests...
						if(strstr($exists[0],'rwxrwxrwx')===false)
							if(($exists[2]!=get_current_user())||($exists[3]!=get_current_user()))
								throw new Exception('WKPDF executable permissions are not 0777 or user/group does not match with current user/group.');
					break;
			}
			return self::$_cmd;
		}
		/**
		 * Force the client to download PDF file when finish() is called.
		 */
		public static $PDF_DOWNLOAD='D';
		/**
		 * Returns the PDF file as a string when finish() is called.
		 */
		public static $PDF_ASSTRING='S';
		/**
		 * When possible, force the client to embed PDF file when finish() is called.
		 */
		public static $PDF_EMBEDDED='I';
		/**
		 * PDF file is saved into the server space when finish() is called. The path is returned.
		 */
		public static $PDF_SAVEFILE='F';
		/**
		 * PDF generated as landscape (vertical).
		 */
		public static $PDF_PORTRAIT='Portrait';
		/**
		 * PDF generated as landscape (horizontal).
		 */
		public static $PDF_LANDSCAPE='Landscape';
		/**
		 * Constructor: initialize command line and reserve temporary file.
		 */
		public function __construct(){
			$this->cmd=self::_getCMD();
		}
		/**
		 * In case where platform detection fails (or you want to disable it), this function is able to let you use your own path to the executable.
		 * @param string $cmd The command line pointing to the WKHTMLTOPDF executable.
		 */
		public function set_cmd($cmd){
			$this->cmd=$cmd;
		}
		/**
		 * Set orientation, use constants from this class.
		 * By default orientation is portrait.
		 * @param string $mode Use constants from this class.
		 */
		public function set_orientation($mode){
			$this->orient=$mode;
		}
		/**
		 * Set page/paper size.
		 * By default page size is A4.
		 * @param string $size Formal paper size (eg; A4, letter...)
		 */
		public function set_page_size($size){
			$this->size=$size;
		}
		/**
		 * Whether to automatically generate a TOC (table of contents) or not.
		 * By default TOC is disabled.
		 * @param boolean $enabled True use TOC, false disable TOC.
		 */
		public function set_toc($enabled){
			$this->toc=$enabled;
		}
		/**
		 * Set the number of copies to be printed.
		 * By default it is one.
		 * @param integer $count Number of page copies.
		 */
		public function set_copies($count){
			$this->copies=$count;
		}
		/**
		 * Whether to print in grayscale or not.
		 * By default it is OFF.
		 * @param boolean True to print in grayscale, false in full color.
		 */
		public function set_grayscale($mode){
			$this->grayscale=$mode;
		}
		/**
		 * Set PDF title. If empty, HTML <title> of first document is used.
		 * By default it is empty.
		 * @param string Title text.
		 */
		public function set_title($text){
			$this->title=$text;
		}
		/**
		 * Set html content.
		 * @param string $html New html content. It *replaces* any previous content.
		 */
		public function set_html($html){
			if($this->tmp!='')throw new Exception('WKPDF html has already been set.');
			do{
				$this->tmp=$GLOBALS['WKPDF_BASE_PATH'].'tmp/'.mt_rand().'.html';
			} while(file_exists($this->tmp));
			if(!file_put_contents($this->tmp,$html))throw new Exception('WKPDF write temporary file failed.');
			$this->url=$GLOBALS['WKPDF_BASE_SITE'].$GLOBALS['WKPDF_BASE_PATH'].'tmp/'.basename($this->tmp);
		}
		/**
		 * Use a URL/path instead of HTML source.
		 * @param string $url Fully qualified URL or absolute path.
		 */
		public function set_url($url){
			$this->url=$url;
		}
		/**
		 * Returns WKPDF print status.
		 * @return string WPDF print status.
		 */
		public function get_status(){
			return $this->status;
		}
		/**
		 * Attempts to return the library's full help.
		 * @return string WKHTMLTOPDF HTML help.
		 */
		public function get_help(){
			$tmp=self::_pipeExec('"'.$this->cmd.'" --extended-help');
			return $tmp['stdout'];
		}
		/**
		 * Print error in output.
		 * @param string $msg The error message.
		 * @param array $out The output.
		 */
		protected static function _retError($msg,$out){
			/*throw new Exception*/ die($msg.'<table>' // changed from exception to die due to stack frame error
				.'<tr><td>RESULT:</td><td><code>'.htmlspecialchars($out['return'],ENT_QUOTES).'</code></td></tr>'
				.'<tr><td>STDERR:</td><td><code>'.htmlspecialchars($out['stderr'],ENT_QUOTES).'</code></td></tr>'
				.'<tr><td>STDOUT:</td><td><code>'.htmlspecialchars($out['stdout'],ENT_QUOTES).'</code></td></tr>'
				.'</table>');
		}
		/**
		 * Add custom argument to the list.
		 * @param string $switch Argument name (eg: --header).
		 * @param string $value Argument value (eg: <b>hi</b>).
		 */
		public function args_add($switch,$value){
			$this->args[$switch]=$value;
		}
		/**
		 * Remove an existing custom argument.
		 * @param string $switch Argument name (eg: --header).
		 */
		public function args_remove($switch){
			if(isset($this->args[$switch]))unset($this->args[$switch]);
		}
		/**
		 * Removes all custom arguments.
		 */
		public function args_clear(){
			$this->args[$switch]=array();
		}
		/**
		 * Helper function that builds the list of arguments.<br>
		 * Do not call this directly.
		 * @return string List of custom arguments.
		 */
		protected function args_build(){
			$res='';
			foreach($this->args as $switch=>$value)$res.=' '.$switch.' '.escapeshellarg($value);
			return $res;
		}
		/**
		 * Convert HTML to PDF.
		 * @return boolean Whether successful or not.
		 */
		public function render(){
			$this->pdf=self::_pipeExec(
				(self::_getOS()!='win' ? $this->cmd : 'cd '.escapeshellarg(dirname($this->cmd)).' && '.basename($this->cmd))
				.(($this->copies>1)?' --copies '.(int)$this->copies:'')				// number of copies
				.' --orientation '.escapeshellarg($this->orient)					// orientation
				.' --page-size '.escapeshellarg($this->size)						// page size
				.($this->toc?' --toc':'')											// table of contents
				.($this->grayscale?' --grayscale':'')								// grayscale
				.(($this->title!='')?' --title '.escapeshellarg($this->title):'')	// title
				.$this->args_build()												// custom arguments
				.' '.escapeshellarg($this->url).' -'								// URL and use STDOUT
			);			//if(strpos(strtolower($this->pdf['stderr']),'error')!==false)self::_retError('WKPDF system error.',$this->pdf);
			if($this->pdf['stdout']=='')self::_retError('WKPDF program error.',$this->pdf);
			$this->status=$this->pdf['stderr'];
			$this->pdf=$this->pdf['stdout'];
			if($this->tmp!='')unlink($this->tmp);
			switch($this->pdf['return']){
				case 7:
					self::_retError('WKPDF system error 7: malformed executable.',$this->pdf);
					return false;
				case 3:
					self::_retError('WKPDF error 401: unauthorized.',$this->pdf);
					return false;
				case 2:
					self::_retError('WKPDF error 404: file not found.',$this->pdf);
					return false;
				case 0:
					return true;
				default:
					self::_retError('WKPDF error '.$this->pdf['return'].'.',$this->pdf);
					return false;
			}
		}
		/**
		 * Return PDF with various options.
		 * @param string $mode How two output (constants from this same class).
		 * @param string $file The PDF's filename (the usage depends on $mode.
		 * @return string|boolean Depending on $mode, this may be success (boolean) or PDF (string).
		 */
		public function output($mode,$file){
			switch($mode){
				case self::$PDF_DOWNLOAD:
					if(!headers_sent()){
						header('Content-Description: File Transfer');
						header('Cache-Control: public, must-revalidate, max-age=0'); // HTTP/1.1
						header('Pragma: public');
						header('Expires: Sat, 26 Jul 1997 05:00:00 GMT'); // Date in the past
						header('Last-Modified: '.gmdate('D, d M Y H:i:s').' GMT');
						// force download dialog
						header('Content-Type: application/force-download');
						header('Content-Type: application/octet-stream', false);
						header('Content-Type: application/download', false);
						header('Content-Type: application/pdf', false);
						// use the Content-Disposition header to supply a recommended filename
						header('Content-Disposition: attachment; filename="'.basename($file).'";');
						header('Content-Transfer-Encoding: binary');
						header('Content-Length: '.strlen($this->pdf));
						echo $this->pdf;
					}else{
						throw new Exception('WKPDF download headers were already sent.');
					}
					break;
				case self::$PDF_ASSTRING:
					return $this->pdf;
					break;
				case self::$PDF_EMBEDDED:
					if(!headers_sent()){
						header('Content-Type: application/pdf');
						header('Cache-Control: public, must-revalidate, max-age=0'); // HTTP/1.1
						header('Pragma: public');
						header('Expires: Sat, 26 Jul 1997 05:00:00 GMT'); // Date in the past
						header('Last-Modified: '.gmdate('D, d M Y H:i:s').' GMT');
						header('Content-Length: '.strlen($this->pdf));
						header('Content-Disposition: inline; filename="'.basename($file).'";');
						echo $this->pdf;
					}else{
						throw new Exception('WKPDF embed headers were already sent.');
					}
					break;
				case self::$PDF_SAVEFILE:
					return file_put_contents($file,$this->pdf);
					break;
				default:
					throw new Exception('WKPDF invalid mode "'.htmlspecialchars($mode,ENT_QUOTES).'".');
			}
			return false;
		}
	}

	/**
	 * This class, which extends WKPDF is for generating a PDF with multiple pages without using CSS page-break.
	 */
	class WKPDF_MULTI extends WKPDF {
		/**
		 * An array of HTML files, this is used internally.
		 * @var array Array of URLs to files.
		 */
		private $html_files=array();
		/**
		 * An array of URLs.
		 * @var array Array of URLs to pages.
		 */
		private $html_urls=array();
		/**
		 * This function doesn't make sense in this context.
		 */
		public function set_html($html){
			die('Calling set_html() not allowed for WKPDF_MULTI class.');
		}
		/**
		 * This function doesn't make sense in this context.
		 */
		public function set_url($url){
			die('Calling set_url() not allowed for WKPDF_MULTI class.');
		}
		/**
		 * Add a new HTML page.
		 * @param string $html Content of HTML page.
		 */
		public function add_html($html){
			do{
				$file=$GLOBALS['WKPDF_BASE_PATH'].'tmp/'.mt_rand().'.html';
			} while(file_exists($file));
			if(!file_put_contents($file,$html))throw new Exception('WKPDF write temporary file failed.');
			$this->html_urls[]=$GLOBALS['WKPDF_BASE_SITE'].$GLOBALS['WKPDF_BASE_PATH'].'tmp/'.basename($file);
			$this->html_files[]=$file;
		}
		/**
		 * Add a new page from URL.
		 * @param string $html URL to HTML page.
		 */
		public function add_url($url){
			$this->html_urls[]=$url;
		}
		/**
		 * Cleans TMP folder from used files.
		 */
		protected function clean_tmp(){
			foreach($this->html_files as $file)unlink($file);
		}
		/**
		 * Convert HTML pages to PDF.
		 */
		public function render(){
			$urls='"'.implode('" "',$this->html_urls).'"';
			if($urls=='""'){
				$this->add_html('<html><body><!--EMPTY PDF--></body></html>');
				$urls='"'.implode('" "',$this->html_urls).'"';
			}
			$this->pdf=self::_pipeExec(
				$this->cmd
				.(($this->copies>1)?' --copies '.$this->copies:'')				// number of copies
				.' --orientation '.$this->orient								// orientation
				.' --page-size '.$this->size									// page size
				.($this->toc?' --toc':'')										// table of contents
				.($this->grayscale?' --grayscale':'')							// grayscale
				.(($this->title!='')?' --title "'.$this->title.'"':'')			// title
				.' '.$urls.' -'													// URL and use STDOUT
			);
			if($this->pdf['stdout']=='')self::_retError('WKPDF program error.',$this->pdf);
			if(((int)$this->pdf['return'])>1)self::_retError('WKPDF shell error.',$this->pdf);
			$this->status=$this->pdf['stderr'];
			$this->pdf=$this->pdf['stdout'];
			$this->clean_tmp();
		}
	}
?>
