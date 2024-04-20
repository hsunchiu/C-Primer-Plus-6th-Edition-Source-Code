#if __STDC_VERSION__ != 201112L
/*https://stackoverflow.com/questions/12637392/c-preprocessor-expand-macro-in-a-warning */
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#pragma message  STR(__STDC_VERSION__)

#undef STR_HELPER
#undef STR

#error Not C11
#endif

