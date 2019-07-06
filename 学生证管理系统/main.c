#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[20];//姓名
    char sex[10];//性别
    long long num;//学号
    char data[20];//入学日期
    int school_system;//学制（学习年限）
    char collge[50];//学院
    char major[50];//专业
    int cla;//班级
    char id[50];//身份证
    struct node *next; //链表指针域
}students;

//extern students* student_list;

students* student_list;

int save_flag;

int student_list_empty()
{
    return student_list->next == NULL;
}

//根据学号查找学生信息
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
    printf("\n========主菜单=========\n|                     |\n");
    printf("|  1.管理学生证信息   |\n");
    printf("|                     |\n|  2.查询学生证信息   |\n");
    printf("|                     |\n|  3.统计学生证信息   |\n");
    printf("|                     |\n|   0.退出系统操作    |\n");
    printf("|                     |\n=======================\n\n");
}
void menu2()
{
    printf("\n========管理学生证信息=========\n\n");
    printf("       1.添加学生证信息\n");
    printf("\n       2.修改学生证信息\n");
    printf("\n       3.删除学生证信息\n");
    printf("\n       4.保存学生证信息\n");
    printf("\n        0.返回主菜单\n");
    printf("\n===============================\n\n");
}
void menu3()
{
    printf("\n========查询学生证信息=========\n\n");
    printf("     1.查询单个学生证信息\n");
    printf("\n   2.查询班级全部学生证信息\n");
    printf("\n        0.返回主菜单\n");
    printf("\n===============================\n\n");
}

void init()//初始化学生信息
{
    student_list=(students*)malloc(sizeof(students));
    student_list->next = NULL;
}

int input()//录入学生证信息
{
    int i=1;
    char ch;
    int f=0;
    system("cls");//清屏
    printf("\n=================================***录入须知***=================================\n");//给使用者备注录入要求，便于统一信息录入格式
    printf("\n1.请按要求输入学生的学生证信息\n2.学生入学日期以xxxx.xx.xx为格式（例如:2019.09.01)\n3.学生学制及所属班级只需输入数字即可（例如学生在1班，则只需输入1即可。）\n4.*切记！录入信息或更改信息后在退出本系统前要在主页面选择保存数据，否则本次操作数据将丢失！\n5.学院专业名称请统一输入标准全称，否则将影响数据统计！\n");
    do
    {
    printf("\n==============================================================================\n");
    printf("\n=======***开始录入学生证信息（若要返回菜单请输入0）***=======\n");
    printf("-------------------------------------------------------------------------------------\n");
        students *stu=(students*)malloc(sizeof(students));
    if(stu==NULL)
    {
        printf("内存分配失败\n");
        return 0;
    }
        printf("\n现在开始录入第%d个学生的学生证信息\n",i);
        printf("学生学号：\n");
        scanf("%lld",&stu->num);
        if(stu->num==0)return 0;
        if((search_student_info(stu->num))!=NULL)
        {
            printf("该学号已经存在学生信息表中！请重新输入。\n");
            continue;
        }
        printf("\n学生姓名：\n");
        scanf("%s",stu->name);
        //gets(stu->name);
        printf("\n学生性别：\n");
        scanf("%s",stu->sex);
        //gets(stu->sex);
        printf("\n学生入学日期：\n");
        scanf("%s",stu->data);
        //gets(stu->data);
        printf("\n学生学制：\n");
        scanf("%d",&stu->school_system);
        printf("\n学生所属学院：\n");
        scanf("%s",stu->collge);
        //gets(stu->collge);
        printf("\n学生所属专业：\n");
        scanf("%s",stu->major);
        //gets(stu->major);
        printf("\n学生所在班级：\n");
        scanf("%d",&stu->cla);
        printf("\n学生身份证号码：\n");
        scanf("%s",stu->id);
        //gets(stu->id);
        i++;
        stu->next=student_list->next;
        student_list->next=stu;
        printf("*****该学生的学生证信息已成功录入！*****\n");
        save_flag=0;
        printf("====*****是否继续录入学生证信息？*****====\n");
        printf("*是：请输入0          *否：请输入1\n");
        scanf("%d",&f);
    }
    while(!f);
    printf("\n**********%d个学生的学生证信息已成功录入！**********\n",i-1);
    //printf("\n=========按回车键返回菜单！===========\n");
    //getch();
    return 1;
}

int modify()//修改学生证信息
{
    int choice,f=0;
    long long modify_num;
    while(f==0)
    {
        system("cls");
        printf("======*****请输入要修改的学生学号（若要返回菜单请输入0）*****======\n");
        scanf("%lld",&modify_num);
        if(modify_num==0)return 0;
        students *stu = search_student_info(modify_num);
        if(stu!=NULL)
        {
            printf("\n\n--------------------当前学生信息---------------------\n\n");
            printf("学生姓名：\n");
            printf("%s\n",stu->name);
            printf("\n学生性别：\n");
            printf("%s\n",stu->sex);
            printf("\n学生学号：\n");
            printf("%lld\n",stu->num);
            printf("\n学生入学日期：\n");
            printf("%s\n",stu->data);
            printf("\n学生学制：\n");
            printf("%d\n",stu->school_system);
            printf("\n学生所属学院：\n");
            printf("%s\n",stu->collge);
            printf("\n学生所属专业：\n");
            printf("%s\n",stu->major);
            printf("\n学生所在班级：\n");
            printf("%d\n",stu->cla);
            printf("\n学生身份证号码：\n");
            printf("%s\n",stu->id);
            printf("--------------------------------------------------------------------\n");
            printf("\n请输入您当前要修改的信息\n");
            printf("\n1.学号\n");
            printf("\n2.姓名\n");
            printf("\n3.性别\n");
            printf("\n4.入学日期\n");
            printf("\n5.学制\n");
            printf("\n6.学院\n");
            printf("\n7.专业\n");
            printf("\n8.班级\n");
            printf("\n9.身份证号码\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:printf("\n请输入修改后的学号：");
                    scanf("%lld",&stu->num);break;
                case 2:printf("\n请输入修改后的姓名：");
                    scanf("%s",stu->name);break;
                case 3:printf("\n请输入修改后的性别：");
                    scanf("%s",stu->sex);break;
                case 4:printf("\n请输入修改后的入学日期：");
                    scanf("%s",stu->data);break;
                case 5:printf("\n请输入修改后的学制：");
                    scanf("%d",&stu->school_system);break;
                case 6:printf("\n请输入修改后的学院：");
                    scanf("%s",stu->collge);break;
                case 7:printf("\n请输入修改后的专业：");
                    scanf("%s",stu->major);break;
                case 8:printf("\n请输入修改后的班级：");
                    scanf("%d",&stu->cla);break;
                case 9:printf("\n请输入修改后的身份证号码：");
                    scanf("%s",stu->id);break;
            }
            printf("\n\n============***修改完毕！***============\n\n");
            save_flag=0;
            printf("\n\n--------------------当前学生信息---------------------\n");
            printf("学生姓名：\n");
            printf("%s\n",stu->name);
            printf("学生性别：\n");
            printf("%s\n",stu->sex);
            printf("学生学号：\n");
            printf("%lld\n",stu->num);
            printf("学生入学日期：\n");
            printf("%s\n",stu->data);
            printf("学生学制：\n");
            printf("%d\n",stu->school_system);
            printf("学生所属学院：\n");
            printf("%s\n",stu->collge);
            printf("学生所属专业：\n");
            printf("%s\n",stu->major);
            printf("学生所在班级：\n");
            printf("%d\n",stu->cla);
            printf("学生身份证号码：\n");
            printf("%s\n",stu->id);
            printf("\n-------------------------------------------------------\n");
        }
        else
        {
            printf("\n=========***该学生不存在！***========\n");
            printf("==========（输入任意键退出）=========\n\n");
            getch();
        }
        printf("==========***您要继续修改吗？***==========\n");
        printf("*是：请输入0          *否：请输入1\n");
        scanf("%d",&f);
        system("cls");
    }
    printf("\n**********操作已执行完毕**********\n");
    //printf("\n===========按回车键返回菜单===========\n");
    //getch();
    return 1;
}

int del()//删除学生证信息
{
    int f=0;
    int f2;
    char ch;
    long long num;
    while(!f)
    {
        printf("======***请输入您要删除的学生证信息的学号***======\n");
        scanf("%lld",&num);
        students *pstu;
        students *qstu;
        if(!search_student_info(num))
        {
            printf("\n======***该学号的学生证信息不存在！请重新输入！***======\n");
            continue;
        }
        pstu=student_list->next;
        qstu=student_list;
        while(pstu->num!=num)
        {
            qstu=pstu;
            pstu=pstu->next;
        }
        printf("\n\n--------------------当前学生信息---------------------\n\n");
        printf("学生姓名：\n");
        printf("%s\n",pstu->name);
        printf("学生性别：\n");
        printf("%s\n",pstu->sex);
        printf("学生学号：\n");
        printf("%lld\n",pstu->num);
        printf("学生入学日期：\n");
        printf("%s\n",pstu->data);
        printf("学生学制：\n");
        printf("%d\n",pstu->school_system);
        printf("学生所属学院：\n");
        printf("%s\n",pstu->collge);
        printf("学生所属专业：\n");
        printf("%s\n",pstu->major);
        printf("学生所在班级：\n");
        printf("%d\n",pstu->cla);
        printf("学生身份证号码：\n");
        printf("%s\n",pstu->id);
        printf("\n--------------------------------------------------------------------\n");
        printf("\n==========***您确定要删除该学生的信息吗？***==========\n");
        printf("*是：请输入0          *否：请输入1\n");
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
            printf("======***已成功删除学号为%lld的学生的学生证信息！***======\n",num);
            save_flag=0;
            printf("===========***您要继续删除吗？***===========\n");
            printf("*是：请输入0          *否：请输入1\n");
            scanf("%d",&f);
        }
    };
    printf("\n**********操作已执行完毕**********\n");
    //printf("\n===========按回车键返回菜单===========\n");
    //getch();
    return 1;
}


//将学生信息保存到文件
int save_file()
{
    FILE *pfile;
    students *pstu;
    pfile=fopen("student.txt","w");
    if(pfile==NULL)
    {
        printf("打开文件失败.\n");
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
//从文件中读取学生信息
int read_file()
{
    FILE *pfile;
    students *pstu;
    pfile=fopen("student.txt","r");
    if(pfile==NULL)
    {
        printf("打开文件失败.\n");
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

//查询单个学生证信息
void Show(long long num)
{
    students *stu=search_student_info(num);
    if(stu == NULL)
    {
        printf("不存在该学号的学生信息.\n");
        return;
    }
    else
    {
        printf("\n\n--------------------当前学生信息---------------------\n\n");
        printf("学生姓名：\n");
        printf("%s\n",stu->name);
        printf("学生性别：\n");
        printf("%s\n",stu->sex);
        printf("学生学号：\n");
        printf("%lld\n",stu->num);
        printf("学生入学日期：\n");
        printf("%s\n",stu->data);
        printf("学生学制：\n");
        printf("%d\n",stu->school_system);
        printf("学生所属学院：\n");
        printf("%s\n",stu->collge);
        printf("学生所属专业：\n");
        printf("%s\n",stu->major);
        printf("学生所在班级：\n");
        printf("%d\n",stu->cla);
        printf("学生身份证号码：\n");
        printf("%s\n",stu->id);
        printf("--------------------------------------------------------------------\n");
    }
}

//查询班级全部学生证信息
void display_class_inf()
{
    students *stu;
    stu=student_list->next;
    char major[50];
    memset(major,0,sizeof(major));
    int cla;
    char grade[10];
    printf("请输入您所要查询的班级的所在年级\n");
    scanf("%s",grade);
    printf("请输入您所要查询的班级的所在专业\n");
    scanf("%s",major);
    printf("请输入您所要查询的班级\n");
    scanf("%d",&cla);
    while(stu!=NULL)
    {
        if((strncmp(grade,stu->data,4)==0)&&(stu->cla==cla)&&strcmp(stu->major,major)==0&&stu->school_system==4)
        {
        printf("学生姓名：\n");
        printf("%s\n",stu->name);
        printf("学生性别：\n");
        printf("%s\n",stu->sex);
        printf("学生学号：\n");
        printf("%lld\n",stu->num);
        printf("学生入学日期：\n");
        printf("%s\n",stu->data);
        printf("学生学制：\n");
        printf("%d\n",stu->school_system);
        printf("学生所属学院：\n");
        printf("%s\n",stu->collge);
        printf("学生所属专业：\n");
        printf("%s\n",stu->major);
        printf("学生所在班级：\n");
        printf("%d\n",stu->cla);
        printf("学生身份证号码：\n");
        printf("%s\n",stu->id);
        printf("\n\n");
        }
        stu=stu->next;
    }
}

void add_up()//统计各种信息
{
    students *stu;
    stu=student_list->next;
    int f;
    char name[20];//姓名
    char sex[10];//性别
    char data[20];//入学日期
    int school_system;//学制（学习年限）
    char collge[50];//学院
    char major[50];//专业
    int cla;//班级
    char grade[10];//年级
    int count=0;//计数
    int c1;
    int c2;
    printf("\n***请选择您要统计的信息：***\n");
    printf("\n1.统计某学院人数\n");
    printf("\n2.统计某专业人数\n");
    printf("\n3.统计某班级人数\n");
    printf("\n4.统计某年级人数\n");
    printf("\n5.统计某学院年级人数\n");
    printf("\n6.统计某专业年级人数\n");
    printf("\n7.统计本校男/女人数\n");
    printf("\n8.统计学院男/女人数\n");
    printf("\n9.统计专业男/女人数\n");
    printf("\n10.统计班级男/女人数\n");
    printf("\n11.统计本校人数\n");
    printf("\n12.统计本科生/研究生人数\n");
    printf("\n0.返回主菜单\n");
    printf("\n-----------------------------\n");
    printf("\n请选择：");
    scanf("%d",&f);
    printf("\n");
    switch(f)
    {
    case 1:
        count=0;
        printf("请输入该学院名称:\n");
        scanf("%s",collge);
        while(stu)
        {
            if(strcmp(collge,stu->collge)==0)
                count++;
            stu=stu->next;
        }
        printf("统计结果：%s当前人数为：%d\n",collge,count);
        break;
    case 2:
        count=0;
        printf("请输入该专业名称:\n");
        scanf("%s",major);
        while(stu)
        {
            if(strcmp(major,stu->major)==0)
                count++;
            stu=stu->next;
        }
        printf("统计结果：%s专业当前人数为：%d\n",major,count);
        break;
    case 3:
        count=0;
        printf("请输入您所要查询的班级的所在年级\n");
        scanf("%s",grade);
        printf("请输入该专业名称:\n");
        scanf("%s",major);
        printf("请输入该班级名称:\n");
        scanf("%d",&cla);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0)&&cla==stu->cla)//通过入学日期来判断学生的年级
                count++;
            stu=stu->next;
        }
        printf("统计结果：%s级%s%d班当前人数为：%d\n",grade,major,cla,count);
        break;
    case 4:
        count=0;
        printf("请输入需要查询的年级:\n");
        scanf("%s",grade);
        while(stu)
        {
            if(strncmp(grade,stu->data,4)==0)
                count++;
            stu=stu->next;
        }
        printf("统计结果：本校%s级当前人数为：%d\n",grade,count);
        break;
    case 5:
        count=0;
        printf("请输入该学院名称:\n");
        scanf("%s",collge);
        printf("请输入需要查询的年级:\n");
        scanf("%s",grade);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(collge,stu->collge)==0))
                count++;
            stu=stu->next;
        }
        printf("统计结果：%s学院%s级当前人数为：%d\n",collge,grade,count);
        break;
    case 6:
        count=0;
        printf("请输入该专业名称:\n");
        scanf("%s",major);
        printf("请输入需要查询的年级:\n");
        scanf("%s",grade);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0))
                count++;
            stu=stu->next;
        }
        printf("统计结果：%s专业%s级当前人数为：%d\n",major,grade,count);
        break;
    case 7:
        c1=0;
        c2=0;
        while(stu)
        {
            if(strcmp("女",stu->sex)==0)
                c1++;
            if(strcmp("男",stu->sex)==0)
                c2++;
            stu=stu->next;
        }
        printf("统计结果：本校男生人数为%d\n本校女生人数为%d\n",c2,c1);
        break;
    case 8:
        c1=0;
        c2=0;
        printf("请输入该学院名称:\n");
        scanf("%s",collge);
        while(stu)
        {
            if((strcmp(collge,stu->collge)==0)&&(strcmp("女",stu->sex)==0))
                c1++;
            if((strcmp(collge,stu->collge)==0)&&(strcmp("男",stu->sex)==0))
                c2++;
            stu=stu->next;
        }
        printf("统计结果：%s中男生人数为%d\n%s中女生人数为%d\n",collge,c2,collge,c1);
        break;
    case 9:
        c1=0;
        c2=0;
        printf("请输入该专业名称:\n");
        scanf("%s",major);
        while(stu)
        {
            if((strcmp(major,stu->major)==0)&&(strcmp("女",stu->sex)==0))
                c1++;
            if((strcmp(major,stu->major)==0)&&(strcmp("男",stu->sex)==0))
                c2++;
            stu=stu->next;
        }
        printf("统计结果：%s专业中男生人数为%d\n%s专业中女生人数为%d\n",major,c2,major,c1);
        break;
    case 10:
        c1=0;
        c2=0;
        printf("请输入该班级所在年级\n");
        scanf("%s",grade);
        printf("请输入该专业名称:\n");
        scanf("%s",major);
        printf("请输入该班级名称:\n");
        scanf("%d",&cla);
        while(stu)
        {
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0)&&(strcmp("女",stu->sex)==0)&&cla==stu->cla)
                c1++;
            if((strncmp(grade,stu->data,4)==0)&&(strcmp(major,stu->major)==0)&&(strcmp("男",stu->sex)==0)&&cla==stu->cla)
                c2++;
            stu=stu->next;
        }
        printf("统计结果：%s级%s%d班中男生人数为%d\n%s%d班中女生人数为%d\n",grade,major,cla,c2,major,cla,c1);
        break;
    case 11:
        count=0;
        while(stu)
        {
            count++;
            stu=stu->next;
        }
        printf("统计结果：本校人数为：%d\n",count);
        break;
    case 12:
        c1=0;
        c2=0;
        while(stu)
        {
            if(stu->school_system==4)
                c1++;
            if(stu->school_system==2||stu->school_system==3)//通过学制判断本科还是研究生
                c2++;
            stu=stu->next;
        }
        printf("统计结果：本校本科生人数为：%d\n本校研究生人数为：%d\n",c1,c2);
        break;
    case 0:
        break;
    default:
        printf("输入错误，请重新选择操作!\n");
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
    printf("\n欢迎使用学生信息管理系统\n");
    printf("\n**************************\n");
    printf("\n--------------------------\n");
    init();
    if(read_file())
        printf("\n*从文件中读取学生信息成功!\n");
    else
        printf("\n*从文件中读取学生信息失败!\n");
    printf("\n--------------------------\n");
    menu1();
    while(1)
    {
        printf("\n请选择操作: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:system("cls");
            menu2();
            while(1)
       {
        printf("\n请选择操作: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:system("cls");
            printf("添加学生证信息\n");
                if(input())
                    printf("\n");
                else
                    printf("添加学生信息失败！\n");
                printf("\n===***按回车键返回子菜单***===\n");
                getch();
                system("cls");
                break;
            case 2:system("cls");
                printf("修改学生证信息\n");
                if(student_list_empty())
                    printf("学生信息表为空，请先添加学生信息！\n");
                else
                {
                    if(modify())
                        printf("\n");
                    else
                        printf("\n修改失败！\n");
                }
                printf("\n===***按回车键返回子菜单***===\n");
                getch();
                system("cls");
                break;
            case 3:system("cls");
                printf("删除学生证信息\n");
                if(student_list_empty())
                    printf("学生信息表为空，请先添加学生信息！\n");
                else
                {
                    if(del())
                        printf("\n");
                    else
                        printf("删除失败！\n");
                }
                printf("\n===***按回车键返回子菜单***===\n");
                getch();
                system("cls");
                break;
            case 4:system("cls");
                printf("保存信息！\n");
                if(student_list_empty())
                    printf("学生信息表为空，请先添加学生信息！\n");
                else
                {
                    if(save_file())
                        printf("保存学生信息成功！\n");
                    else
                        printf("保存学生信息失败！\n");
                }
                printf("\n===***按回车键返回子菜单***===\n");
                getch();
                system("cls");
                break;
            case 0:system("cls");
                if(save_flag==0)
            {
                printf("\n***************************************************\n\n");
                printf("提示：您刚执行的操作还未保存，确定要返回主菜单吗？\n");
                printf("\n      是：选择1                  否：选择0     \n");
                printf("\n***************************************************\n\n");
                printf("\n请选择：");
                scanf("%d",&f1);
                if(f1==0)
                {
                    c=9;
                    system("cls");
                    break;
                }
            }
                system("cls");
                printf("返回主菜单:-\)\n\n");
                break;
            default:
                printf("输入错误，请重新选择操作!\n");
        }
        if(c==0)break;
        menu2();
       }
       break;
            case 2:system("cls");
                menu3();
                while(1)
    {
        printf("\n请选择操作: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:system("cls");
                printf("查看单个学生信息\n");
                while(1)
                {
                    if(student_list_empty())
                    printf("学生信息表为空，请先添加学生信息！\n");
                  else
                   {
                    printf("\n请输入学生证号：\n");
                    scanf("%lld",&num);
                    Show(num);
                    printf("\n\n======***查询完毕，是否要继续查询学生证信息？***======\n\n");
                    printf("*是：输入1            *否：输入0\n\n请输入：");
                    scanf("%d",&f);
                    system("cls");
                    if(f==0)break;
                    printf("继续查询单个学生证信息\n\n");
                   }
                }
                break;
            case 2:system("cls");
                printf("查看班级全部学生信息\n");
                while(1)
                {
                    if(student_list_empty())
                    printf("学生信息表为空，请先添加学生信息！\n");
                    else
                    {
                    display_class_inf();
                    printf("\n\n======***查看完毕，是否要继续查看班级学生信息？***======\n\n");
                    printf("*是：输入1            *否：输入0\n\n请输入：");
                    scanf("%d",&f);
                    system("cls");
                    if(f==0)break;
                    printf("继续查看班级全部学生信息\n\n");
                    }
                }
                break;
            case 0:system("cls");
                printf("返回主菜单:-\)\n\n");
                break;
            default:
                printf("输入错误，请重新选择操作!\n");
        }
        if(c==0)break;
        menu3();
        }
        break;

            case 3:system("cls");
                printf("统计各类学生证信息\n");
                while(1)
                {
                    add_up();
                    printf("\n\n======***查询完毕，是否要继续查询统计信息？***======\n\n");
                    printf("*是：输入1            *否：输入0\n\n请输入：");
                    scanf("%d",&f);
                    system("cls");
                    if(f==0)break;
                    printf("继续查询统计信息\n\n");
                }
                break;
            case 0:system("cls");
                if(save_flag==0)
            {
                printf("\n*****************************************************************\n\n");
                printf("提示：您刚执行的操作还未保存，数据将会丢失！确定要退出本程序吗？\n");
                printf("\n      是：选择1                  否：选择0     \n");
                printf("\n*****************************************************************\n\n");
                printf("\n请选择：");
                scanf("%d",&f1);
                if(f1==0)
                {
                    c=9;
                    system("cls");
                    break;
                }
            }
                system("cls");
                printf("欢迎下次使用,再见！:-\)\n");
                system("pause");
                exit(0);
                break;
            default:
                printf("输入错误，请重新选择操作!\n");
        }
        menu1();
    }
    return 0;
}
