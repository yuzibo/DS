 /* algo2-3.c ʵ���㷨2.7�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.c"

 void MergeList(SqList La,SqList Lb,SqList *Lc) /* �㷨2.7 */
 { /* ��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С� */
   /* �鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
   ElemType *pa,*pa_last,*pb,*pb_last,*pc;
   pa=La.elem;
   pb=Lb.elem;
   (*Lc).listsize=(*Lc).length=La.length+Lb.length;/*����InitList()�����ձ�Lc */
   pc=(*Lc).elem=(ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
   if(!(*Lc).elem) /* �洢����ʧ�� */
     exit(OVERFLOW);
   pa_last=La.elem+La.length-1;
   pb_last=Lb.elem+Lb.length-1;
   while(pa<=pa_last&&pb<=pb_last) /* ��La�ͱ�Lb���ǿ� */
   { /* �鲢 */
     if(*pa<=*pb)
       *pc++=*pa++;
     else
       *pc++=*pb++;
   }
   while(pa<=pa_last) /* ��La�ǿ��ұ�Lb�� */
     *pc++=*pa++; /* ����La��ʣ��Ԫ�� */
   while(pb<=pb_last) /* ��Lb�ǿ��ұ�La�� */
     *pc++=*pb++; /* ����Lb��ʣ��Ԫ�� */
 }

 void print(ElemType *c)
 {
   printf("%d ",*c);
 }

 void main()
 {
   SqList La,Lb,Lc;
   int j;
   InitList(&La); /* �����ձ�La */
   for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�� */
     ListInsert(&La,j,j);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* �����ձ�Lb */
   for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�� */
     ListInsert(&Lb,j,2*j);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   MergeList(La,Lb,&Lc);
   printf("Lc= "); /* �����Lc������ */
   ListTraverse(Lc,print);
 }