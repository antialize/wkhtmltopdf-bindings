<?php
/**
 * Since setting up WKHTMLTOPDF in a PHP environment is particularly troublesome,
 * I've decided to write this script to check for preconditions and test the current
 * enviroment and various system settings.  Christian Sciberras 27/06/2010
 *
 * !! SECURITY WARNING !!
 * This file may disclose sensitive info about your server.
 * REMOVE THIS FILE FROM YOUR PRODUCTION SERVER.
 */

/** Small tool/script for generating hash=>version pairs of a set of wkhtmltopdf executables
$hashes='';
foreach(glob('bin/*') as $dir)
	if(is_dir($dir)){
		$name=str_replace(array('_','bin/wkhtmltopdf-','-static-','amd64','i386'),array(' ','','',' 64bit',' 32bit'),$dir);
		if(file_exists($dir.'/wkhtmltopdf-i386')){
			$hashes.='\''.md5_file($dir.'/wkhtmltopdf-i386').'\' => \''.$name."',\r\n";
		}elseif(file_exists($dir.'/wkhtmltopdf-amd64')){
			$hashes.='\''.md5_file($dir.'/wkhtmltopdf-amd64').'\' => \''.$name."',\r\n";
		}
	}
die('<pre>'.$hashes.'</pre>');
*/

require_once('wkhtmltopdf.php');

class WKPDF_DBG extends WKPDF { // debugger class extends WKPDF class to gain access to protected methods
	/**
	 * @return string Returns the kind of OS (win,lin,osx).
	 */
	public static function os(){
		return self::_getOS();
	}
	/**
	 * @var array This array holds md5 hashes of known executable versions. This is to detect the file version, NOT a security measure!!
	 */
	protected static $versions=array(
		'hash'                             => 'version',
		'fa6553e6db1b4e5f139a4a227305868c' => '0.10.0 rc1',
		'af2e951fd859233d3c749ae2f62d1857' => '0.10.0 rc1',
		'2870d5c819196f5fe6cccfe9c621a0b7' => '0.10.0 rc1',
		'43aa77d943a6b3053422aea8a4b0f75a' => '0.10.0 beta4 64bit',
		'1f47dce2755ee7d5f8f9ba20f8ad5b3d' => '0.10.0 beta4 32bit',
		'cd8c2d843aa2527a27ea20c7fd011051' => '0.10.0 beta3 64bit',
		'957c193e4bb94a8837d9d11bd31473b9' => '0.10.0 beta3 32bit',
		'2b2ef37c75aaa7fd5138ed63e5867cff' => '0.9.0 64bit',
		'5fd04b20c815964746feae5d205ad25d' => '0.9.0 32bit',
		'b5005eba4fc70aaa7497ac31256ad801' => '0.9.0 beta2 64bit',
		'ae5bbcc5482a5c2ce2f18b299b34c0e3' => '0.9.0 beta2 32bit',
		'598c17fc1a00d06139f0d860002c45f1' => '0.9.0 beta3 64bit',
		'6b7b124fe8cbf18b567cbd036e0eceb0' => '0.9.0 beta3 32bit',
		'b7aacd9965adf777da0aa9889ddb1f3c' => '0.9.0 beta4 64bit',
		'1131e03d6bd6a8cedea5c290dd827ecd' => '0.9.0 beta4 32bit',
		'5f3027450421f753a42cb82b10957dbc' => '0.9.1 64bit',
		'a0dae0d6ce0e0fe8754069947b00a7b4' => '0.9.1 32bit',
		'238f39412b15acfa21b69697e6568697' => '0.9.2 64bit',
		'839ce650620b6582032e66fad456ac11' => '0.9.2 32bit',
		'65291ca8cc371863b74ae9c6ac0acfe1' => '0.9.3 64bit',
		'f5978ecedf1d86898f9fa25cb7090609' => '0.9.3 32bit',
		'4913ba06cb0898d21f4e5e8f607f1ddc' => '0.9.4 64bit',
		'323981838611b2f39b2ea07aab99780f' => '0.9.4 32bit',
		'89df50be1c69eb099bb4bfbbc8e7c1ba' => '0.9.5 64bit',
		'aeca4b7d77238e07a47fc2f254b4c0c3' => '0.9.5 32bit',
		'1c039b81e9d539805992a04fee96f192' => '0.9.6 64bit',
		'eeabdab03bff108d969876dc80af1c43' => '0.9.6 32bit',
		'63f855f8bc7a22d63d8ec1e86f8f8788' => '0.9.7 64bit',
		'8c4c289e6cc38a74c31f7312b1be59c9' => '0.9.7 32bit',
		'63f855f8bc7a22d63d8ec1e86f8f8788' => '0.9.8 64bit',
		'8c4c289e6cc38a74c31f7312b1be59c9' => '0.9.8 32bit',
		'bbbf179ae462305d51ad9a762d73e2a5' => '0.9.9 64bit',
		'6c5b72184e88805d30e0bfdab2e22a53' => '0.9.9 32bit',
	);
	/**
	 * Writes a new test section.
	 * @param string $title Section name/title.
	 */
	protected static function section_begin($title){
		echo '<table style="font-family:Arial;" cellspacing="2" cellpadding="4"><tr><td colspan="2" style="font-size:18px;"><b>'.$title.'</b></td></tr>';
	}
	/**
	 * Finishes writing an open section.
	 */
	protected static function section_end(){
		echo '</table>';
	}
	/**
	 * Add key/value pair to current section.
	 * @param string $key The key name.
	 * @param string $value The related value.
	 * @param string $color Web/hex color without leading hash.
	 */
	protected static function section_inspect($key,$value,$color='FFF'){
		echo '<tr><td valign="top" nowrap="nowrap" style="background:#EEE;">'.$key.'</td><td style="background:#'.$color.';"><pre>'.$value.'</pre></td></tr>';
	}
	/**
	 * Function for attempting to recognize wkhtmltopdf version from file data.
	 * @return string|null If recognized, the version is returned as a string, otherwise null is returned.
	 */
	protected static function detect(){
		if(!file_exists(self::_getCMD()))return false;
		$hash=md5_file(self::_getCMD());
		return isset(self::$versions[$hash]) ? self::$versions[$hash] : null;
	}
	const CL_GREEN	= '8F8';
	const CL_RED	= 'E88';
	public static function test(){
		$pev=self::detect();
		$exe=is_executable(self::_getCMD());
		$fex=file_exists(self::_getCMD());
		$ecd='';
		switch(WKPDF_DBG::os()){
			case 'win': $ecd=self::_pipeExec('CD');  break;
			case 'lin': $ecd=self::_pipeExec('PWD'); break;
			case 'osx': $ecd=self::_pipeExec('PWD'); break;
		}
		if(is_array($ecd))$ecd=$ecd['stdout'];
		self::section_begin('System Info &amp; Settings');
		self::section_inspect('Detected OS:',self::_getOS(),self::_getOS()!='' ? self::CL_GREEN : self::CL_RED);
		self::section_inspect('Detected CPU:',self::_getCPU(),self::_getCPU()!='' ? self::CL_GREEN : self::CL_RED);
		self::section_inspect('Generated CMD:',self::_getCMD(),self::_getCMD()!='' ? self::CL_GREEN : self::CL_RED);
		self::section_inspect('Executable MD5:',$fex ? md5_file(self::_getCMD()) : 'File Not Found',$fex ? self::CL_GREEN : self::CL_RED);
		self::section_inspect('Executable:',$exe ? 'Yes' : 'No',$exe ? self::CL_GREEN : self::CL_RED);
		self::section_inspect('Base path: ',$GLOBALS['WKPDF_BASE_PATH']);
		self::section_inspect('Site path: ',$GLOBALS['WKPDF_BASE_SITE']);
		self::section_inspect('WinI path: ',$GLOBALS['WKPDF_WINI_PATH']);
		self::section_inspect('PHP Script CWD: ',getcwd(),getcwd()!==false ? self::CL_GREEN : self::CL_RED);
		self::section_inspect('PHP Exec CWD: ',$ecd=='' ? 'fail' : $ecd,$ecd!='' ? self::CL_GREEN : self::CL_RED);
		self::section_inspect('PHP Version: ',phpversion());
		self::section_inspect('Safe Mode: ',ini_get('safe_mode') ? 'On' : 'Off',ini_get('safe_mode') ? self::CL_RED : self::CL_GREEN);
		self::section_inspect('Wkhtmltopdf Version: ',$pev ? $pev : 'Not Recognized',$pev ? self::CL_GREEN : self::CL_RED);
		self::section_end();

		self::section_begin('Run Basic Commands');
		$cmd='dir';
		$out=self::_pipeExec($cmd);
		self::section_inspect('CMD: ',$cmd);
		self::section_inspect('STDOUT: ',$out['stdout']);
		self::section_inspect('STDERR: ',$out['stderr']);
		self::section_inspect('RETURN: ',$out['return']);
		self::section_end();
		self::section_begin('Test Run');
		try {
			$pdf=new self();
			self::section_inspect('CMD: ',$pdf->cmd);
			$pdf->set_url('http://google.com/');
			$pdf->render();
			self::section_inspect('Status: ','success',self::CL_GREEN);
			self::section_inspect('STDOUT: ',substr($pdf->pdf['stdout'],0,100));
			self::section_inspect('STDERR: ',$pdf->pdf['stderr']);
			self::section_inspect('RETURN: ',$pdf->pdf['return']);
		} catch (Exception $e) {
			self::section_inspect('Status: ','failure',self::CL_RED);
			self::section_inspect('Reason: ',$e->getMessage());
			self::section_inspect('In File: ',$e->getFile());
			self::section_inspect('On Line: ',$e->getLine());
			self::section_inspect('Stack Trace: ',$e->getTraceAsString());
		}
		self::section_end();

		self::section_begin('sTrace Run');
		$cmd='strace '.self::_getCMD().' --version';
		$out=self::_pipeExec($cmd);
		self::section_inspect('CMD: ',$cmd);
		self::section_inspect('STDOUT: ',$out['stdout']);
		self::section_inspect('STDERR: ',$out['stderr']);
		self::section_inspect('RETURN: ',$out['return']);
		self::section_end();

		self::section_begin('CPU Info');
		$cmd='cat /proc/cpuinfo';
		$out=self::_pipeExec($cmd);
		self::section_inspect('CMD: ',$cmd);
		self::section_inspect('STDOUT: ',$out['stdout']);
		self::section_inspect('STDERR: ',$out['stderr']);
		self::section_inspect('RETURN: ',$out['return']);
		self::section_end();
	}
}

WKPDF_DBG::test();
?>
