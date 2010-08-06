#include <objbase.h>
#include "wkhtmltoxcom.h"
#include <vector>
#include <wkhtmltox/pdf.h>
#include <wkhtmltox/image.h>

extern LONG volatile objCount;

template <typename T>
class ObjMan {
public:
  std::vector<int> free;
  std::vector<T*> objects;

  inline T * get(size_t number) {
    if (number < 0 || number >= objects.size()) return NULL;
    return objects[number];
  }

  inline int set(T * e) {
    if (free.size() == 0) {
      objects.push_back(e);
      return objects.size()-1;
    }
    int number = free.back();
    free.pop_back();
    objects[number] = e;
    return number;
  }

  inline void unset(int number) {
    objects[number] = NULL;
    free.push_back(number);
  }
};

class CWkHtmlToPdf: public IWkHtmlToPdf {
private:
  LONG volatile refCount;
  
  ObjMan<wkhtmltopdf_global_settings> gsm;
  ObjMan<wkhtmltopdf_object_settings> osm;
  ObjMan<wkhtmltopdf_converter> csm;
public:
  HRESULT __stdcall QueryInterface(REFIID iid, void ** v);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();

  HRESULT __stdcall extendedQt(BOOL * res);
  HRESULT __stdcall version(const unsigned char * * version);
  HRESULT __stdcall createGlobalSettings(int * object);
  HRESULT __stdcall createObjectSettings(int * object);
  HRESULT __stdcall setGlobalSetting(int settings, const unsigned char * name, const unsigned char * value);
  HRESULT __stdcall getGlobalSetting(int settings, const unsigned char * name, unsigned char * value, int vs);
  HRESULT __stdcall setObjectSetting(int settings, const unsigned char * name, const unsigned char * value);
  HRESULT __stdcall getObjectSetting(int settings, const unsigned char * name, unsigned char * value, int vs);
  HRESULT __stdcall createConverter(int globalSettings, int * converter);
  HRESULT __stdcall destroyConverter(int converter);
  HRESULT __stdcall convert(int converter);
  HRESULT __stdcall addResource(int converter, int settings, const unsigned char * data);
  HRESULT __stdcall currentPhase(int converter, int * currentPhase);
  HRESULT __stdcall phaseCount(int converter, int * phaseCount);
  HRESULT __stdcall phaseDescription(int converter, int phase, const unsigned char * *);
  HRESULT __stdcall progressString(int converter, const unsigned char * * );
  HRESULT __stdcall httpErrorCode(int converter, int * errorCode);

  CWkHtmlToPdf();
  ~CWkHtmlToPdf();
};

class CWkHtmlToImage: public IWkHtmlToImage {
private:
  LONG volatile refCount;

  ObjMan<wkhtmltoimage_global_settings> gsm;
  ObjMan<wkhtmltoimage_converter> csm;
public:
  HRESULT __stdcall QueryInterface(REFIID iid, void ** v);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();

  HRESULT __stdcall extendedQt(BOOL * res);
  HRESULT __stdcall version(const unsigned char * * version);
  HRESULT __stdcall createGlobalSettings(int * object);
  HRESULT __stdcall setGlobalSetting(int settings, const unsigned char * name, const unsigned char * value);
  HRESULT __stdcall getGlobalSetting(int settings, const unsigned char * name, unsigned char * value, int vs);
  HRESULT __stdcall createConverter(int globalSettings, int * converter);
  HRESULT __stdcall destroyConverter(int converter);
  HRESULT __stdcall convert(int converter);
  HRESULT __stdcall addResource(int converter, int settings, const unsigned char * data);
  HRESULT __stdcall currentPhase(int converter, int * currentPhase);
  HRESULT __stdcall phaseCount(int converter, int * phaseCount);
  HRESULT __stdcall phaseDescription(int converter, int phase, const unsigned char * *);
  HRESULT __stdcall progressString(int converter, const unsigned char * * );
  HRESULT __stdcall httpErrorCode(int converter, int * errorCode);

  CWkHtmlToImage();
  ~CWkHtmlToImage();
};
