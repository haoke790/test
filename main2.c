#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "file.h"
//缓冲区在内存里，文件在磁盘（硬盘）里
//文件函数：打开文件：fopen（）;关闭文件：fclose（）;
//文件定位：fseek();(改变文件位置指针的位置）rewind();（使文件位置指针重新至于文件开头）ftell();（返回文件位置指针的当前值）（获取文件大小） 
//文件状态：feof();(若到函数末尾，函数值为真）ferror();（若对文件操作出错，函数值为真）,perror():省略...clearerr()（使ferror和feof函数值置零）
//fread:读取文件。  fwrite:写如文件 
//stdio.h中有FILE 
//注意r+与w+的区别： 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	FILE *fp=NULL;
	char buff[1024]={0}; 
	//案例1 
//	//wb+代表以二进制方式，打开文件用于写入 
//	fp=fopen("./user.txt","wb+");
//	//fwrite参数：要写的数据的地址；单个数据的大小（字节）；多少个这样的数据；文件指针/
//	//这里“123456789”本质上是一个char*地址， 
//	fwrite("123456789",9,1,fp);
//	getch(); 
//	//刷新缓冲区！可以立即把内容写到文件中，使得数据立即从输入文件缓冲区传到文件里面 
//	fflush(fp);
//	getch();
//	fclose(fp); 
//	
	
	
	//案例2
//	fp=fopen("./data/user.txt","ab+");//会写到末尾，不会清空文件，若文件不存在会创建一个新的文件。而wb会清空文件然后从最开头写 
//	fwrite("123",strlen("123"),1,fp);//会覆盖原本开头位置的字母或数字 
	
	
	//案例3 
	fp=file_open("./data/user.txt");
	fseek(fp,0,SEEK_END);//偏移到文件尾 ，无返回值  
	fwrite("你好",strlen("你好"),1,fp); 
	//计算文件大小
	int size=ftell(fp); 
	printf("size:%d\n",size);
	printf("size:%d\n",file_getSize("./data/user.txt"));
	
	
	
	//案例4
	fp=file_open("./data/user.txt");
	fread(buff,1024,1,fp);
	printf("%s\n",buff);
	
	
	 
	//使用后关掉 
	fclose(fp);
	 
	return 0;
}
