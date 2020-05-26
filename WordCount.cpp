#include<stdio.h>
#include<string.h>
//计算字符数 
int countChar(char *p){
	int count=0;
	char words; 
	FILE *fp;
	if((fp=fopen(p,"r")) == NULL)
    {
        printf("读取文件失败！请重试！");
        return -1;
    }
    words = fgetc(fp);
    while(words!=EOF)
    {
    	//根据输入不同判断字符还是单词 
    	count++;
        words = fgetc(fp);
    }
    fclose(fp);
    printf("字符数：%d",count);
} 
//计算单词数
int countWords(char *p){
	int wCount=1;//默认单词数为1 
	char words;
	FILE *fp;
	if((fp=fopen(p,"r")) == NULL)
    {
        printf("读取文件失败！请重试！");
        return -1;
    }
    words = fgetc(fp);
    while(words!=EOF)
    {
    	//根据输入不同判断字符还是单词 	
		if(words == ','||words == ' ')
		{
			wCount++;
		}
		words = fgetc(fp);
	}
	printf("单词数：%d",wCount);
}
int main(int argc,char *argv[])
{
    // 判断参数是否存在 
    if(argc!=3)
    {
        printf("请输入正确的三个参数！");
        return -1;
    }
    // 判断函数的调用方式是-c还是-w 
    if(argv[1][1]=='w'){
    	countWords(argv[2]);
	}else {
	  countChar(argv[2]);
	}
    //调用不同函数 
    return 0;
}

