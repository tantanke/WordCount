#include<stdio.h>
#include<string.h>
//�����ַ��� 
int countChar(char *p){
	int count=0;
	char words; 
	FILE *fp;
	if((fp=fopen(p,"r")) == NULL)
    {
        printf("��ȡ�ļ�ʧ�ܣ������ԣ�");
        return -1;
    }
    words = fgetc(fp);
    while(words!=EOF)
    {
    	//�������벻ͬ�ж��ַ����ǵ��� 
    	count++;
        words = fgetc(fp);
    }
    fclose(fp);
    printf("�ַ�����%d",count);
} 
//���㵥����
int countWords(char *p){
	int wCount=1;//Ĭ�ϵ�����Ϊ1 
	char words;
	FILE *fp;
	if((fp=fopen(p,"r")) == NULL)
    {
        printf("��ȡ�ļ�ʧ�ܣ������ԣ�");
        return -1;
    }
    words = fgetc(fp);
    while(words!=EOF)
    {
    	//�������벻ͬ�ж��ַ����ǵ��� 	
		if(words == ','||words == ' ')
		{
			wCount++;
		}
		words = fgetc(fp);
	}
	printf("��������%d",wCount);
}
int main(int argc,char *argv[])
{
    // �жϲ����Ƿ���� 
    if(argc!=3)
    {
        printf("��������ȷ������������");
        return -1;
    }
    // �жϺ����ĵ��÷�ʽ��-c����-w 
    if(argv[1][1]=='w'){
    	countWords(argv[2]);
	}else {
	  countChar(argv[2]);
	}
    //���ò�ͬ���� 
    return 0;
}

