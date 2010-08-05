#include "wkhtmltoxcom.h"
#include <stdio.h>

int main() {
  IWkHtmlToPdf * wkhtmltopdf; 
  HRESULT h;
  char buff[1234];
  
  CoInitialize(NULL);
  
  h = CoCreateInstance( &CWkHtmlToPdf_CLSID,
			NULL, 
			CLSCTX_INPROC_SERVER, 
			&IID_IWkHtmlToPdf,
			&wkhtmltopdf); 
  
  printf("%d\n", wkhtmltopdf->vtbl->extendedQt(wkhtmltopdf));
  
  wkhtmltopdf->vtbl->release(wkhtmltopdf);

  
}
