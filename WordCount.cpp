#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int count=0,wCount=1;//���ʵ�Ĭ������Ϊһ 
    int isC=0,isW=0;//�жϵ��ú��� 
    char words;
    FILE *fp;
    // �жϲ����Ƿ���� 
    if(argc!=3)
    {
        printf("��������ȷ������������");
        return -1;
    }
    // �жϺ����ĵ��÷�ʽ��-c����-w 
    if(argv[1][1]=='w'){
    	isW=1;
	}else {
	  isC=1;
	}
    // ���ļ� 
    if((fp=fopen(argv[2],"r")) == NULL)
    {
        printf("��ȡ�ļ�ʧ�ܣ������ԣ�");
        return -1;
    }
    //��ȡȫ���ַ� �����ж� 
    words = fgetc(fp);
    while(words!=EOF)
    {
    	//�������벻ͬ�ж��ַ����ǵ��� 
    	if(isC == 1){
    		count++;
		} else{
			// ��¼���� 
			if(words == ','||words == ' ')
			{
				wCount++;
			}
		}
        words = fgetc(fp);
    }
    //������ 
    if(isC==1){
    	printf("�ַ�����%d",count);
	} else{
		printf("��������%d",wCount);
	}
  
    fclose(fp);
    return 0;
}

