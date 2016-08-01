 /* algo9-1.c ����bo9-1.c(˳�������)�ĳ��� */
 #include"c1.h"
 #define N 5 /* ����Ԫ�ظ��� */
 typedef int KeyType; /* ��ؼ�����Ϊ���� */
 typedef struct /* ����Ԫ������(�Խ̿���ͼ9.1�߿��ɼ�Ϊ��) */
 {
   long number; /* ׼��֤�� */
   char name[9]; /* ����(4�����ּ�1����������־) */
   int politics; /* ���� */
   int Chinese; /* ���� */
   int English; /* Ӣ�� */
   int math; /* ��ѧ */
   int physics; /* ���� */
   int chemistry; /* ��ѧ */
   int biology; /* ���� */
   KeyType key; /* �ؼ�������ӦΪKeyType,����ӦΪkey,��bo9-1.c��һ�� */
 } ElemType;
 ElemType r[N]={{179324,"�η���",85,89,98,100,93,80,47},
                {179325,"�º�",85,86,88,100,92,90,45},
                {179326,"½��",78,75,90,80,95,88,37},
                {179327,"��ƽ",82,80,78,98,84,96,40},
                {179328,"��С��",76,85,94,57,77,69,44}}; /* ȫ�ֱ��� */
 #define total key /* �����ܷ�(total)Ϊ�ؼ��� */
 #include"c9.h"
 #include"c9-1.h"
 #include"bo9-1.c"

 void print(ElemType c) /* Traverse()���õĺ��� */
 {
   printf("%-8ld%-8s%4d%5d%5d%5d%5d%5d%5d%5d\n",c.number,c.name,c.politics,c.Chinese,c.English,c.math,c.physics,c.chemistry,c.biology,c.total);
 }

 void main()
 {
   SSTable st;
   int i,s;
   for(i=0;i<N;i++) /* �����ܷ� */
     r[i].total=r[i].politics+r[i].Chinese+r[i].English+r[i].math+r[i].physics+r[i].chemistry+r[i].biology;
   Creat_Seq(&st,N); /* ��ȫ�����������̬���ұ�st */
   printf("׼��֤��  ����  ���� ���� ���� ��ѧ ���� ��ѧ ���� �ܷ�\n");
   Traverse(st,print); /* ��˳�������̬���ұ�st */
   printf("������������˵��ܷ�: ");
   scanf("%d",&s);
   i=Search_Seq(st,s); /* ˳����� */
   if(i)
     print(*(st.elem+i));
   else
     printf("û�ҵ�\n");
   Destroy(&st);
 }