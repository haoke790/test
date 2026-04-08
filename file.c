#include"file.h"


/*
函数名：file_open
函数功能：打开文件，若文件不存在会新建，否则就是正常打开 
参数： fileName_文件名 
返回值：文件指针 
*/
FILE *file_open(const char *fileName)
{
	FILE *fp;
	fp=fopen(fileName,"rb+");
	if(fp==NULL){
		perror("打开文件失败");
		fp=fopen(fileName,"wb+");
	}
	return fp;
}


/*
函数名：file_getSize 
函数功能：获得文件大小 
参数： fileName:函数名 
返回值： 文件大小。打开文件失败返回-1 
*/
int file_getSize(const char *fileName){
	FILE *fp;
	fp=fopen(fileName,"rb+");
	if(fp==NULL){
		perror("文件打开失败");
		return -1;
	}
	fseek(fp,0,SEEK_END);
	return ftell(fp);
}
