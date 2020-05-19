#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int count=0,wCount=1;//单词的默认数量为一 
    int isC=0,isW=0;//判断调用函数 
    char words;
    FILE *fp;
    // 判断参数是否存在 
    if(argc!=3)
    {
        printf("请输入正确的三个参数！");
        return -1;
    }
    // 判断函数的调用方式是-c还是-w 
    if(argv[1][1]=='w'){
    	isW=1;
	}else {
	  isC=1;
	}
    // 打开文件 
    if((fp=fopen(argv[2],"r")) == NULL)
    {
        printf("读取文件失败！请重试！");
        return -1;
    }
    //获取全部字符 进行判断 
    words = fgetc(fp);
    while(words!=EOF)
    {
    	//根据输入不同判断字符还是单词 
    	if(isC == 1){
    		count++;
		} else{
			// 记录数量 
			if(words == ','||words == ' ')
			{
				wCount++;
			}
		}
        words = fgetc(fp);
    }
    //输出结果 
    if(isC==1){
    	printf("字符数：%d",count);
	} else{
		printf("单词数：%d",wCount);
	}
  
    fclose(fp);
    return 0;
}

