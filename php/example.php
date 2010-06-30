<?php

/**
 * !! SECURITY WARNING !!
 * This file may be used maliciously on your server.
 * REMOVE THIS FILE FROM YOUR PRODUCTION SERVER.
 */

// load class file
require_once('wkhtmltopdf.php');

if(isset($_REQUEST['URL'])){ // if URL is set...
	// generate PDF given URL and force embed
	try {
		$urls=explode(';',$_REQUEST['URL']);
		if(count($urls)<=1){
			$pdf=new WKPDF();
			$pdf->set_url($urls[0]);
			$pdf->render();
			$pdf->output(WKPDF::$PDF_EMBEDDED,'converted.pdf');
		}else{
			$pdf=new WKPDF_MULTI();
			foreach($urls as $url)$pdf->add_url($url);
			$pdf->render();
			$pdf->output(WKPDF::$PDF_EMBEDDED,'converted.pdf');
		}
	}catch(Exception $e){
		die('Exception (line '.$e->getLine().'): '.$e->getMessage());
	}
}else{ // otherwise, output page code
	$url='http://code.google.com/p/wkhtmltopdf/'; // initial demo url

?><html>
	<head>
		<title>Example Page</title>
		<script type="text/javascript">
			function convert(url){
				document.getElementById('url').value=url;
				document.getElementById('frm').src='index.php?URL='+encodeURIComponent(url);
			}
			function convertAll(urls){
				document.getElementById('url').value=urls.join(';');
				document.getElementById('frm').src='index.php?URL='+encodeURIComponent(urls.join(';'));
			}
			window.onresize=function(){
				document.getElementById('frm').style.height=(document.body.clientHeight-35)+'px';
			}
			window.onload=function(){
				document.getElementById('frm').style.height=(document.body.clientHeight-35)+'px';
			}
		</script><style type="text/css">
			body {
				font-family:Arial; color:#005000; font-size:14px; margin:0; padding:0; overflow:hidden;
			}
			#toolbar {
				background:#9FB82E; border-bottom:3px solid #83A000; left:0; padding:4px; position:fixed; right:0; top:0;
			}
			#url {
				background:#E1FA71; border:1px solid #83A000; color:#005000;
			}
			#convert, #samples input {
				padding:2px; background:#9FB82E; border:2px solid #83A000; color:#005000; vertical-align:middle;
			}
			#convert:hover, #samples input:hover {
				padding:2px; background:#E1FA71; border:2px solid #9FB82E;
			}
			#samples input {
				width:16px; height:16px;
			}
			#samples {
				padding-left: 20px;
			}
			#frm {
				margin-top:35px; height:0;
			}
		</style>
	</head><body>

		<div id="toolbar">
			<span id="address">
				Address: <input type="text" style="width:300px;" id="url" value="<?php echo $url; ?>">
				<input id="convert" type="button" value="convert" onclick="convert(document.getElementById('url').value);">
			</span>
			<span id="samples">
				<input type="image" onclick="convert('http://www.bing.com/');" src="http://www.bing.com/favicon.ico" alt="">
				<input type="image" onclick="convert('http://www.google.com/');" src="http://www.google.com.mt/favicon.ico" alt="">
				<input type="image" onclick="convert('http://www.pastebin.com/');" src="http://www.pastebin.com/favicon.ico" alt="">
				<input type="image" onclick="convert('http://www.facebook.com/');" src="http://www.facebook.com/favicon.ico" alt="">
				<input type="image" onclick="convert('http://www.twitter.com/');" src="http://www.twitter.com/favicon.ico" alt="">
				<input type="image" onclick="convert('http://geekz.co.uk/lovesraymond/archive/eler-highlights-2008');" src="http://geekz.co.uk/favicon.ico" alt="">
				&nbsp;&nbsp;&nbsp;
				<input type="image" onclick="convertAll([
					'http://www.bing.com/',
					'http://www.google.com/',
					'http://search.yahoo.com/',
					'http://www.altavista.com/',
					'http://www.dogpile.com/'
				]);" src="http://storage.conduit.com/images/searchengines/search_icon.gif" alt="">
			</span>
		</div>

		<iframe id="frm" src="index.php?URL=<?php echo htmlspecialchars($url,ENT_QUOTES); ?>" width="100%" frameborder="0"></iframe>
	</body>
</html><?php

	}
?>