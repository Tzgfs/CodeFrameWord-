#include <iostream>
#include <assert.h>
using namespace std;

void memcpy(void *dest, const void *source, size_t count){
    assert((NULL!=dest)&&(NULL!=source));
    char *tmp_source, *tmp_dest;
    tmp_source = (char *)source;
    tmp_dest = (char *)dest;
    if((dest + count<source)||( source + count )<dest))
    {//如果没有重叠区域
        while(count--){
            *tmp_dest ++ =* tmp_source++;
        }
    }
    else
    {//如果有重叠(反向拷贝)
        tmp_source+=count-1;
        tmp_dest+=count-1;
        while(count--)
            *--tmp_dest=*--tmp;
    }
}

int main()
{

    return 0;
}

