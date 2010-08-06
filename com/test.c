#include "wkhtmltoxcom.h"
#include "guid.h"
#include <stdio.h>

int main() {
  IWkHtmlToPdf * i;
  IWkHtmlToPdfVtbl * v;
  HRESULT h;
  char buff[1234];
  int gs, conv, o;
  const char * version;
  BOOL ext;

  CoInitialize(NULL);
  
  h = CoCreateInstance( &CLSID_CWkHtmlToPdf,
			NULL, 
			CLSCTX_INPROC_SERVER, 
			&IID_IWkHtmlToPdf,
			&i); 
  v = i->lpVtbl;
  
  v->version(i, &version);
  v->extendedQt(i, &ext);
  printf("Converting document using wkhtmltopdf version %s, %susing extended QT\n",
	 version, ext?"":"*not* ");

  v->createGlobalSettings(i, &gs);
  v->setGlobalSetting(i, gs, "out", "foo.pdf");
  
  v->createConverter(i, gs, &conv);
  
  v->createObjectSettings(i, &o);
  v->setObjectSetting(i, o, "page", "newz.dk");
  
  v->addResource(i, conv, o, NULL);
  v->convert(i, conv);
  
  v->Release(i);
}
