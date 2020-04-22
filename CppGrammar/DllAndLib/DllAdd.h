#ifdef MY_DLL_EXPORTS
#   define MY_DLL_EXP __declspec(dllexport)
#else
#   define MY_DLL_EXP __declspec(dllimport)
#endif

class MY_DLL_EXP HelloDll {
public:
    void hello();
};