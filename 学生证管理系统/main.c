#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[20];//����
    char sex[10];//�Ա�
    long long num;//ѧ��
    char data[20];//��ѧ����
    int school_system;//ѧ�ƣ�ѧϰ���ޣ�
    char collge[50];//ѧԺ
    char major[50];//רҵ
    int cla;//�༶
    char id[50];//���֤
    struct node *next; //����ָ����
}students;

//extern students* student_list;

students* student_list;

int save_flag;

int student_list_empty()
{
    return student_list->next == NULL;
}

//����ѧ�Ų���ѧ����Ϣ
students *search_student_info(long long num)
{
    students *stu;
    stu=student_list->next;
    while(stu&&stu->num!=num)
    {
        stu=stu->next;
    }
    return stu;
}

void menu1()
{
    printf("\n========���˵�=========\n|                     |\n");
    printf("|  1.����ѧ��֤��Ϣ   |\n");
    printf("|                     |\n|  2.��ѯѧ��֤��Ϣ   |\n");
    printf("|                     |\n|  3.ͳ��ѧ��֤��Ϣ   |\n");
    printf("|                     |\n|   0.�˳�ϵͳ����    |\n");
    printf("|                     |\n=======================\n\n");
}
void menu2()
{
    printf("\n========����ѧ��֤��Ϣ=========\n\n");
    printf("       1.���ѧ��֤��Ϣ\n");
    printf("\n       2.�޸�ѧ��֤��Ϣ\n");
    printf("\n       3.ɾ��ѧ��֤��Ϣ\n");
    printf("\n       4.����ѧ��֤��Ϣ\n");
    printf("\n        0.�������˵�\n");
    printf("\n===============================\n\n");
}
void menu3()
{
    printf("\n========��ѯѧ��֤��Ϣ=========\n\n");
    printf("     1.��ѯ����ѧ��֤��Ϣ\n");
    printf("\n   2.��ѯ�༶ȫ��ѧ��֤��Ϣ\n");
    printf("\n        0.�������˵�\n");
    printf("\n===============================\n\n");
}

void init()//��ʼ��ѧ����Ϣ
{
    student_list=(students*)malloc(sizeof(students));
    student_list->next = NULL;
}

int input()//¼��ѧ��֤��Ϣ
{
    int i=1;
    char ch;
    int f=0;
    system("cls");//����
    printf("\n=================================***¼����֪***=================================\n");//��ʹ���߱�ע¼��Ҫ�󣬱���ͳһ��Ϣ¼���ʽ
    printf("\n1.�밴Ҫ������ѧ����ѧ��֤��Ϣ\n2.ѧ����ѧ������xxxx.xx.xxΪ��ʽ������:2019.09.01)\n3.ѧ��ѧ�Ƽ������༶ֻ���������ּ��ɣ�����ѧ����1�࣬��ֻ������1���ɡ���\n4.*�мǣ�¼����Ϣ�������Ϣ�����˳���ϵͳǰҪ����ҳ��ѡ�񱣴����ݣ����򱾴β������ݽ���ʧ��\n5.ѧԺרҵ������ͳһ�����׼ȫ�ƣ�����Ӱ������ͳ�ƣ�\n");
    do
    {
    printf("\n==============================================================================\n");
    printf("\n=======***��ʼ¼��ѧ��֤��Ϣ����Ҫ���ز˵�������0��***=======\n");
    printf("-------------------------------------------------------------------------------------\n");
        students *stu=(students*)malloc(sizeof(students));
    if(stu==NULL)
    {
        printf("�ڴ����ʧ��\n");
        return 0;
    }
        printf("\n���ڿ�ʼ¼���%d��ѧ����ѧ��֤��Ϣ\n",i);
        printf("ѧ��ѧ�ţ�\n");
        scanf("%lld",&stu->num);
        if(stu->num==0)return 0;
        if((search_student_info(stu->num))!=NULL)
        {
            printf("��ѧ���Ѿ�����ѧ����Ϣ���У����������롣\n");
            continue;
        }
        printf("\nѧ��������\n");
        scanf("%s",stu->name);
        //gets(stu->name);
        printf("\nѧ���Ա�\n");
        scanf("%s",stu->sex);
        //gets(stu->sex);
        printf("\nѧ����ѧ���ڣ�\n");
        scanf("%s",stu->data);
        //gets(stu->data);
        printf("\nѧ��ѧ�ƣ�\n");
        scanf("%d",&stu->school_system);
        printf("\nѧ������ѧԺ��\n");
        scanf("%s",stu->collge);
        //gets(stu->collge);
        printf("\nѧ������רҵ��\n");
        scanf("%s",stu->major);
        //gets(stu->major);
        printf("\nѧ�����ڰ༶��\n");
        scanf("%d",&stu->cla);
        printf("\nѧ�����֤���룺\n");
        scanf("%s",stu->id);
        //gets(stu->id);
        i++;
        stu->next=student_list->next;
        student_list->next=stu;
        printf("*****��ѧ����ѧ��֤��Ϣ�ѳɹ�¼�룡*****\n");
        save_flag=0;
        printf("====*****�Ƿ����¼��ѧ��֤��Ϣ��*****====\n");
        printf("*�ǣ�������0          *��������1\n");
        scanf("%d",&f);
    }
    while(!f);
    printf("\n**********%d��ѧ����ѧ��֤��Ϣ�ѳɹ�¼�룡**********\n",i-1);
    //printf("\n=========���س������ز˵���===========\n");
    //getch();
    return 1;
}

int modify()//�޸�ѧ��֤��Ϣ
{
    int choice,f=0;
    long long modify_num;
    while(f==0)
    {
        system("cls");
        printf("======*****������Ҫ�޸ĵ�ѧ��ѧ�ţ���Ҫ���ز˵�������0��*****======\n");
        scanf("%lld",&modify_num);
        if(modify_num==0)return 0;
        students *stu = search_student_info(modify_num);
        if(stu!=NULL)
        {
            printf("\n\n--------------------��ǰѧ����Ϣ---------------------\n\n");
            printf("ѧ��������\n");
            printf("%s\n",stu->name);
            printf("\nѧ���Ա�\n");
            printf("%s\n",stu->sex);
            printf("\nѧ��ѧ�ţ�\n");
            printf("%lld\n",stu->num);
            printf("\nѧ����ѧ���ڣ�\n");
            printf("%s\n",stu->data);
            printf("\nѧ��ѧ�ƣ�\n");
            printf("%d\n",stu->school_system);
            printf("\nѧ������ѧԺ��\n");
            printf("%s\n",stu->collge);
            printf("\nѧ������רҵ��\n");
            printf("%s\n",stu->major);
            printf("\nѧ�����ڰ༶��\n");
            printf("%d\n",stu->cla);
            printf("\nѧ�����֤���룺\n");
            printf("%s\n",stu->id);
            printf("--------------------------------------------------------------------\n");
            printf("\n����������ǰҪ�޸ĵ���Ϣ\n");
            printf("\n1.ѧ��\n");
            printf("\n2.����\n");
            printf("\n3.�Ա�\n");
            printf("\n4.��ѧ����\n");
            printf("\n5.ѧ��\n");
            printf("\n6.ѧԺ\n");
            printf("\n7.רҵ\n");
            printf("\n8.�༶\n");
            printf("\n9.���֤����\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:printf("\n�������޸ĺ��ѧ�ţ�");
                    scanf("%lld",&stu->num);break;
                case 2:printf("\n�������޸ĺ��������");
                    scanf("%s",stu->name);break;
                case 3:printf("\n�������޸ĺ���Ա�");
                    scanf("%s",stu->sex);break;
                case 4:printf("\n�������޸ĺ����ѧ���ڣ�");
                    scanf("%s",stu->data);break;
                case 5:printf("\n�������޸ĺ��ѧ�ƣ�");
                    scanf("%d",&stu->school_system);break;
                case 6:printf("\n�������޸ĺ��ѧԺ��");
                    scanf("%s",stu->collge);break;
                case 7:printf("\n�������޸ĺ��רҵ��");
                    scanf("%s",stu->major);break;
                case 8:printf("\n�������޸ĺ�İ༶��");
                    scanf("%d",&stu->cla);break;
                case 9:printf("\n�������޸ĺ�����֤���룺");
                    scanf("%s",stu->id);break;
            }
            printf("\n\n============***�޸���ϣ�***============\n\n");
            save_flag=0;
            printf("\n\n--------------------��ǰѧ����Ϣ---------------------\n");
            printf("ѧ��������\n");
            printf("%s\n",stu->name);
            printf("ѧ���Ա�\n");
            printf("%s\n",stu->sex);
            printf("ѧ��ѧ�ţ�\n");
            printf("%lld\n",stu->num);
            printf("ѧ����ѧ���ڣ�\n");
            printf("%s\n",stu->data);
            printf("ѧ��ѧ�ƣ�\n");
            printf("%d\n",stu->school_system);
            printf("ѧ������ѧԺ��\n");
            printf("%s\n",stu->collge);
            printf("ѧ������רҵ��\n");
            printf("%s\n",stu->major);
            printf("ѧ�����ڰ༶��\n");
            printf("%d\n",stu->cla);
            printf("ѧ�����֤���룺\n");
            printf("%s\n",stu->id);
            printf("\n-------------------------------------------------------\n");
        }
        else
        {
            printf("\n=========***��ѧ�������ڣ�***========\n");
            printf("==========������������˳���=========\n\n");
            getch();
        }
        printf("==========***��Ҫ�����޸���***==========\n");
        printf("*�ǣ�������0          *��������1\n");
        scanf("%d",&f);
        system("cls");
    }
    printf("\n**********������ִ�����**********\n");
    //printf("\n===========���س������ز˵�===========\n");
    //getch();
    return 1;
}

int del()//ɾ��ѧ��֤��Ϣ
{
    int f=0;
    int f2;
    char ch;
    long long num;
    while(!f)
    {
        printf("======***��������Ҫɾ����ѧ��֤��Ϣ��ѧ��***======\n");
        scanf("%lld",&num);
        students *pstu;
        students *qstu;
        if(!search_student_info(num))
        {
            printf("\n======***��ѧ�ŵ�ѧ��֤��Ϣ�����ڣ����������룡***======\n");
            continue;
        }
        pstu=student_list->next;
        qstu=student_list;
        while(pstu->num!=num)
        {
            qstu=pstu;
            pstu=pstu->next;
        }
        printf("\n\n--------------------��ǰѧ����Ϣ---------------------\n\n");
        printf("ѧ��������\n");
        printf("%s\n",pstu->name);
        printf("ѧ���Ա�\n");
        printf("%s\n",pstu->sex);
        printf("ѧ��ѧ�ţ�\n");
        printf("%lld\n",pstu->num);
        printf("ѧ����ѧ���ڣ�\n");
        printf("%s\n",pstu->data);
        printf("ѧ��ѧ�ƣ�\n");
        printf("%d\n",pstu->school_system);
        printf("ѧ������ѧԺ��\n");
        printf("%s\n",pstu->collge);
        printf("ѧ������רҵ��\n");
        printf("%s\n",pstu->major);
        printf("ѧ�����ڰ༶��\n");
        printf("%d\n",pstu->cla);
        printf("ѧ�����֤���룺\n");
        printf("%s\n",pstu->id);
        printf("\n--------------------------------------------------------------------\n");
        printf("\n==========***��ȷ��Ҫɾ����ѧ������Ϣ��***==========\n");
        printf("*�ǣ�������0          *��������1\n");
        scanf("%d",&f2);
        if(f2==1)
        {
            f2=0;
            break;
        }
        else
        {
            qstu->next=pstu->next;
            free(pstu);
            printf("======***�ѳɹ�ɾ��ѧ��Ϊ%lld��ѧ����ѧ��֤��Ϣ��***======\n",num);
            save_flag=0;
            printf("===========***��Ҫ����ɾ����***===========\n");
            printf("*�ǣ�������0          *��������1\n");
            scanf("%d",&f);
        }
    };
    printf("\n**********������ִ�����**********\n");
    //printf("\n===========���س������ز˵�===========\n");
    //getch();
    return 1;
}


//��ѧ����Ϣ���浽�ļ�
int save_file()
{
    FILE *pfile;
    students *pstu;
    pfile=fopen("student.txt","w");
    if(pfile==NULL)
    {
        printf("���ļ�ʧ��.\n");
        return 0;
    }
    pstu = student_list->next;
    while(pstu)
    {
        fprintf(pfile,"%s\t%s\t%lld\t%s\t%d\t%s\t%s\t%d\t%s\n",pstu->name,pstu->sex,pstu->num,pstu->data,pstu->school_system,pstu->collge,pstu->major,pstu->cla,pstu->id);
        pstu=pstu->next;
    }
    save_flag=1;
    fclose(pfile);
    return 1;
}
//���ļ��ж�ȡѧ����Ϣ
int read_file()
{
    FILE *pfile;
    students *pstu;
    pfile=fopen("student.txt","r");
    if(pfile==NULL)
    {
        printf("���ļ�ʧ��.\n");
        return 0;
    }
    while(!feof(pfile))
    {
        pstu = (students*)malloc(sizeof(students));
        fscanf(pfile,"%s\t%s\t%lld\t%s\t%d\t%s\t%s\t%d\t%s\n",pstu->name,pstu->sex,&pstu->num,pstu->data,&pstu->school_system,pstu->collge,pstu->major,&pstu->cla,pstu->id);
        pstu->next = student_list->next;
        student_list->next = pstu;
    }
    fclose(pfile);
    return 1;
}

//��ѯ����ѧ��֤��Ϣ
void Show(long long num)
{
    students *stu=search_student_info(num);
    if(stu == NULL)
    {
        printf("�����ڸ�ѧ�ŵ�ѧ����Ϣ.\n");
        return;
    }
    else
    {
        printf("\n\n--------------------��ǰѧ����Ϣ---------------------\n\n");
        printf("ѧ��������\n");
        printf("%s\n",stu->name);
        printf("ѧ���Ա�\n");
        printf("%s\n",stu->sex);
        printf("ѧ��ѧ�ţ�\n");
        printf("%lld\n",stu->num);
        printf("ѧ����ѧ���ڣ�\n");
        printf("%s\n",stu->data);
        printf("ѧ��ѧ�ƣ�\n");
        printf("%d\n",stu->school_system);
        printf("ѧ������ѧԺ��\n");
        printf("%s\n",stu->collge);
        printf("ѧ������רҵ��\n");
        printf("%s\n",stu->major);
        printf("ѧ�����ڰ༶��\n");
        printf("%d\n",stu->cla);
        printf("ѧ�����֤���룺\n");
        printf("%s\n",stu->id);
        printf("--------------------------------------------------------------------\n");
    }
}

//��ѯ�༶ȫ��ѧ��֤��Ϣ
void display_class_inf()
{
    students *stu;
    stu=student_list->next;
    char major[50];
    memset(major,0,sizeof(major));
    int cla;
    char grade[10];
    printf("����������Ҫ��ѯ�İ༶�������꼶\n");
    scanf("%s",grade);
    printf("����������Ҫ��ѯ�İ༶������רҵ\n");
    scanf("%s",major);
    printf("����������Ҫ��ѯ�İ༶\n");
    scanf("%d",&cla);
    while(stu!=NULL)
    {
        if((strncmp(grade,stu->data,4)==0)&&(stu->cla==cla)&&strcmp(stu->major,major)==0&&stu->school_system==4)
        {
        printf("ѧ��������\n");
        printf("%s\n",stu->name);
        printf("ѧ���Ա�\n");
        printf("%s\n",stu->sex);
        printf("ѧ��ѧ�ţ�\n");
        printf("%lld\n",stu->num);
        printf("ѧ����ѧ���ڣ�\n");
        printf("%s\n",stu->data);
        printf("ѧ��ѧ�ƣ�\n");
        printf("%d\n",stu->school_system);
        printf("ѧ������ѧԺ��\n");
        printf("%s\n",stu->collge);
        printf("ѧ������רҵ��\n");
        printf("%s\n",stu->major);
        printf("ѧ�����ڰ༶��\n");
        printf("%d\n",stu->cla);
        printf("ѧ�����֤���룺\n");
        printf("%s\n",stu->id);
        printf("\n\n");
        }
        stu=stu->next;
    }
}

void add_up()//ͳ�Ƹ�����Ϣ
{
    students *stu;
    stu=student_list->next;
    int f;
    char name[20];//����
    char sex[10];//�Ա�
    char data[20];//��ѧ����
    int school_system;//ѧ�ƣ�ѧϰ���ޣ�
    char collge[50];//ѧԺ
    char major[50];//רҵ
    int cla;//�༶
    char grade[10];//�꼶
    int count=0;//����
    int c1;
    int c2;
    printf("\n***��ѡ����Ҫͳ�Ƶ���Ϣ��***\n");
    printf("\n1.ͳ��ĳѧԺ����\n");
    printf("\n2.ͳ��ĳרҵ����\n");
    printf("\n3.ͳ��ĳ�༶����\n");
    printf("\n4.ͳ��ĳ�꼶����\n");
    printf("\n5.ͳ��ĳѧԺ�꼶����\n");
    printf("\n6.ͳ��ĳרҵ�꼶����\n");
    printf("\n7.ͳ�Ʊ�У��/Ů����\n");
    printf("\n8.ͳ��ѧԺ��/Ů����\n");
    printf("\n9.ͳ��רҵ��/Ů����\n");
    printf("\n10.ͳ�ư༶��/Ů����\n");
    printf("\n11.ͳ�Ʊ�У����\n");
    printf("\n12.ͳ�Ʊ�����/�о�������\n");
    printf("\n0.�������˵�\n");
    printf("\n-----------------------------\n");
    printf("\n��ѡ��");
    scanf("%d",&f);
    printf("\n");
    switch(f)
    {
    case 1:
        count=0;
        printf("�������ѧԺ����:\n");
        scanf("%s",collge);
        while(stu)
        {
            if(strcmp(collge,stu->collge)==0)
                count++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%s��ǰ����Ϊ��%d\n",collge,count);
        break;
    case 2:
        count=0;
        printf("�������רҵ����:\n");
        scanf("%s",major);
        while(stu)
        {
            if(strcmp(major,stu->major)==0)
                count++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%sרҵ��ǰ����Ϊ��%d\n",major,count);
        break;
    case 3:
        count=0;
        printf("����������Ҫ��ѯ�İ༶�������꼶\n");
        scanf("%s",grade);
        printf("�������רҵ����:\n");
        scanf("%s",major);
        printf("������ð༶����:\n");
        scanf("%d",&cla);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0)&&cla==stu->cla)//ͨ����ѧ�������ж�ѧ�����꼶
                count++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%s��%s%d�൱ǰ����Ϊ��%d\n",grade,major,cla,count);
        break;
    case 4:
        count=0;
        printf("��������Ҫ��ѯ���꼶:\n");
        scanf("%s",grade);
        while(stu)
        {
            if(strncmp(grade,stu->data,4)==0)
                count++;
            stu=stu->next;
        }
        printf("ͳ�ƽ������У%s����ǰ����Ϊ��%d\n",grade,count);
        break;
    case 5:
        count=0;
        printf("�������ѧԺ����:\n");
        scanf("%s",collge);
        printf("��������Ҫ��ѯ���꼶:\n");
        scanf("%s",grade);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(collge,stu->collge)==0))
                count++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%sѧԺ%s����ǰ����Ϊ��%d\n",collge,grade,count);
        break;
    case 6:
        count=0;
        printf("�������רҵ����:\n");
        scanf("%s",major);
        printf("��������Ҫ��ѯ���꼶:\n");
        scanf("%s",grade);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0))
                count++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%sרҵ%s����ǰ����Ϊ��%d\n",major,grade,count);
        break;
    case 7:
        c1=0;
        c2=0;
        while(stu)
        {
            if(strcmp("Ů",stu->sex)==0)
                c1++;
            if(strcmp("��",stu->sex)==0)
                c2++;
            stu=stu->next;
        }
        printf("ͳ�ƽ������У��������Ϊ%d\n��УŮ������Ϊ%d\n",c2,c1);
        break;
    case 8:
        c1=0;
        c2=0;
        printf("�������ѧԺ����:\n");
        scanf("%s",collge);
        while(stu)
        {
            if((strcmp(collge,stu->collge)==0)&&(strcmp("Ů",stu->sex)==0))
                c1++;
            if((strcmp(collge,stu->collge)==0)&&(strcmp("��",stu->sex)==0))
                c2++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%s����������Ϊ%d\n%s��Ů������Ϊ%d\n",collge,c2,collge,c1);
        break;
    case 9:
        c1=0;
        c2=0;
        printf("�������רҵ����:\n");
        scanf("%s",major);
        while(stu)
        {
            if((strcmp(major,stu->major)==0)&&(strcmp("Ů",stu->sex)==0))
                c1++;
            if((strcmp(major,stu->major)==0)&&(strcmp("��",stu->sex)==0))
                c2++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%sרҵ����������Ϊ%d\n%sרҵ��Ů������Ϊ%d\n",major,c2,major,c1);
        break;
    case 10:
        c1=0;
        c2=0;
        printf("������ð༶�����꼶\n");
        scanf("%s",grade);
        printf("�������רҵ����:\n");
        scanf("%s",major);
        printf("������ð༶����:\n");
        scanf("%d",&cla);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0)&&(strcmp("Ů",stu->sex)==0)&&cla==stu->cla)
                c1++;
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0)&&(strcmp("��",stu->sex)==0)&&cla==stu->cla)
                c2++;
            stu=stu->next;
        }
        printf("ͳ�ƽ����%s��%s%d������������Ϊ%d\n%s%d����Ů������Ϊ%d\n",grade,major,cla,c2,major,cla,c1);
        break;
    case 11:
        count=0;
        while(stu)
        {
            count++;
            stu=stu->next;
        }
        printf("ͳ�ƽ������У����Ϊ��%d\n",count);
        break;
    case 12:
        c1=0;
        c2=0;
        while(stu)
        {
            if(stu->school_system==4)
                c1++;
            if(stu->school_system==2||stu->school_system==3)//ͨ��ѧ���жϱ��ƻ����о���
                c2++;
            stu=stu->next;
        }
        printf("ͳ�ƽ������У����������Ϊ��%d\n��У�о�������Ϊ��%d\n",c1,c2);
        break;
    case 0:
        break;
    default:
        printf("�������������ѡ�����!\n");
    }
}

int main()
{
    int choice;
    int f=0;
    int f1=0;
    save_flag=1;
    int c;
    long long num;
    printf("\n**************************\n");
    printf("\n��ӭʹ��ѧ����Ϣ����ϵͳ\n");
    printf("\n**************************\n");
    printf("\n--------------------------\n");
    init();
    if(read_file())
        printf("\n*���ļ��ж�ȡѧ����Ϣ�ɹ�!\n");
    else
        printf("\n*���ļ��ж�ȡѧ����Ϣʧ��!\n");
    printf("\n--------------------------\n");
    menu1();
    while(1)
    {
        printf("\n��ѡ�����: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:system("cls");
            menu2();
            while(1)
       {
        printf("\n��ѡ�����: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:system("cls");
            printf("���ѧ��֤��Ϣ\n");
                if(input())
                    printf("\n");
                else
                    printf("���ѧ����Ϣʧ�ܣ�\n");
                printf("\n===***���س��������Ӳ˵�***===\n");
                getch();
                system("cls");
                break;
            case 2:system("cls");
                printf("�޸�ѧ��֤��Ϣ\n");
                if(student_list_empty())
                    printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ��\n");
                else
                {
                    if(modify())
                        printf("\n");
                    else
                        printf("\n�޸�ʧ�ܣ�\n");
                }
                printf("\n===***���س��������Ӳ˵�***===\n");
                getch();
                system("cls");
                break;
            case 3:system("cls");
                printf("ɾ��ѧ��֤��Ϣ\n");
                if(student_list_empty())
                    printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ��\n");
                else
                {
                    if(del())
                        printf("\n");
                    else
                        printf("ɾ��ʧ�ܣ�\n");
                }
                printf("\n===***���س��������Ӳ˵�***===\n");
                getch();
                system("cls");
                break;
            case 4:system("cls");
                printf("������Ϣ��\n");
                if(student_list_empty())
                    printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ��\n");
                else
                {
                    if(save_file())
                        printf("����ѧ����Ϣ�ɹ���\n");
                    else
                        printf("����ѧ����Ϣʧ�ܣ�\n");
                }
                printf("\n===***���س��������Ӳ˵�***===\n");
                getch();
                system("cls");
                break;
            case 0:system("cls");
                if(save_flag==0)
            {
                printf("\n***************************************************\n\n");
                printf("��ʾ������ִ�еĲ�����δ���棬ȷ��Ҫ�������˵���\n");
                printf("\n      �ǣ�ѡ��1                  ��ѡ��0     \n");
                printf("\n***************************************************\n\n");
                printf("\n��ѡ��");
                scanf("%d",&f1);
                if(f1==0)
                {
                    c=9;
                    system("cls");
                    break;
                }
            }
                system("cls");
                printf("�������˵�:-\)\n\n");
                break;
            default:
                printf("�������������ѡ�����!\n");
        }
        if(c==0)break;
        menu2();
       }
       break;
            case 2:system("cls");
                menu3();
                while(1)
    {
        printf("\n��ѡ�����: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:system("cls");
                printf("�鿴����ѧ����Ϣ\n");
                while(1)
                {
                    if(student_list_empty())
                    printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ��\n");
                  else
                   {
                    printf("\n������ѧ��֤�ţ�\n");
                    scanf("%lld",&num);
                    Show(num);
                    printf("\n\n======***��ѯ��ϣ��Ƿ�Ҫ������ѯѧ��֤��Ϣ��***======\n\n");
                    printf("*�ǣ�����1            *������0\n\n�����룺");
                    scanf("%d",&f);
                    system("cls");
                    if(f==0)break;
                    printf("������ѯ����ѧ��֤��Ϣ\n\n");
                   }
                }
                break;
            case 2:system("cls");
                printf("�鿴�༶ȫ��ѧ����Ϣ\n");
                while(1)
                {
                    if(student_list_empty())
                    printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ��\n");
                    else
                    {
                    display_class_inf();
                    printf("\n\n======***�鿴��ϣ��Ƿ�Ҫ�����鿴�༶ѧ����Ϣ��***======\n\n");
                    printf("*�ǣ�����1            *������0\n\n�����룺");
                    scanf("%d",&f);
                    system("cls");
                    if(f==0)break;
                    printf("�����鿴�༶ȫ��ѧ����Ϣ\n\n");
                    }
                }
                break;
            case 0:system("cls");
                printf("�������˵�:-\)\n\n");
                break;
            default:
                printf("�������������ѡ�����!\n");
        }
        if(c==0)break;
        menu3();
        }
        break;

            case 3:system("cls");
                printf("ͳ�Ƹ���ѧ��֤��Ϣ\n");
                while(1)
                {
                    add_up();
                    printf("\n\n======***��ѯ��ϣ��Ƿ�Ҫ������ѯͳ����Ϣ��***======\n\n");
                    printf("*�ǣ�����1            *������0\n\n�����룺");
                    scanf("%d",&f);
                    system("cls");
                    if(f==0)break;
                    printf("������ѯͳ����Ϣ\n\n");
                }
                break;
            case 0:system("cls");
                if(save_flag==0)
            {
                printf("\n*****************************************************************\n\n");
                printf("��ʾ������ִ�еĲ�����δ���棬���ݽ��ᶪʧ��ȷ��Ҫ�˳���������\n");
                printf("\n      �ǣ�ѡ��1                  ��ѡ��0     \n");
                printf("\n*****************************************************************\n\n");
                printf("\n��ѡ��");
                scanf("%d",&f1);
                if(f1==0)
                {
                    c=9;
                    system("cls");
                    break;
                }
            }
                system("cls");
                printf("��ӭ�´�ʹ��,�ټ���:-\)\n");
                system("pause");
                exit(0);
                break;
            default:
                printf("�������������ѡ�����!\n");
        }
        menu1();
    }
    return 0;
}
