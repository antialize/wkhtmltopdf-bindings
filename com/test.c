#include "wkhtmltoxcom.h"
#include <stdio.h>

int main() {
  IWkHtmlToPdf * i;
  IWkHtmlToPdfVtbl * v;
  HRESULT h;
  char buff[1234];
  void * gs, * conv, * o;
  
  CoInitialize(NULL);
  
  h = CoCreateInstance( &CWkHtmlToPdf_CLSID,
			NULL, 
			CLSCTX_INPROC_SERVER, 
			&IID_IWkHtmlToPdf,
			&i); 
  v = i->vtbl;
  printf("Converting document using wkhtmltopdf version %s, %susing extended QT\n",
	 v->version(),
	 v->extendedQt()?"":"*not* "
	 );
  
  gs = v->createGlobalSettings();
  v->setGlobalSetting(gs, "out", "foo.pdf");
  
  conv = v->createConverter(gs);
  
  o = v->createObjectSettings();
  v->setObjectSetting(o, "page", "newz.dk");
  
  v->addResource(conv, o, NULL);
  v->convert(conv);
  
  v->release(i);
}
