#include<stdio.h>
#include<string.h>

struct basic_info
{

    char name[30];
    int id;
    char email[30];
    long long int phone;
    char address[30];
    char dob[30];

};


struct prev
{

    char institution[30];
    int year_of_exam;
    double grade;

};


struct exam
{
    double quiz;
    double mid;
    double assign;
    double fin;
    double grade;
};
struct course
{

    char course_name[30];
    char faculty_name[30];
    int credit;
    struct exam ex;

};
struct semester
{

    char semester_name[30];
    int num_of_course;
    struct course cou[6];


};
struct nsu_info
{

    char department [30];
    int num_of_sem;
    double prevcgpa;
    int credit_comp;
    struct semester sem;


};
struct student_info
{

    struct basic_info bi;
    struct prev ssc;
    struct prev hsc;
    struct nsu_info ni;

};



int main()
{

    int i,j,k;
    double q1,q2,q3,m1,m2,as,fin,sum,new_cgpa;
    FILE * fp;
    FILE * fp1;
    FILE * fp2;
    fp = fopen("student_info.txt", "w");
    fp1 = fopen("student_grade.txt", "w");
    fp2 = fopen("student_cgpa.txt", "w");

    struct student_info st[100];
    for(i=0;i<1;i++)
    {
        printf("********Basic Information********\n");
        printf("Enter name:");
        scanf("%s", st[i].bi.name);
        fprintf(fp, "%s ", st[i].bi.name);
        fprintf(fp1, "%s ", st[i].bi.name);
        fprintf(fp2, "%s ", st[i].bi.name);

        printf("Enter ID:");
        scanf("%d",&st[i].bi.id);
        fprintf(fp, "%d ", st[i].bi.id);
        fprintf(fp1, "%d ", st[i].bi.id);
        fprintf(fp2, "%d ", st[i].bi.id);
        printf("Enter email:");
        scanf("%s", st[i].bi.email);
        fprintf(fp, "%s ", st[i].bi.email);
        printf("Enter phone:");
        scanf("%d",&st[i].bi.phone);
        fprintf(fp, "%d ", st[i].bi.phone);
        printf("Enter address:");
        scanf("%s", st[i].bi.address);
        fprintf(fp, "%s ", st[i].bi.address);
        printf("Enter date of birth:");
        scanf("%s", st[i].bi.dob);
        fprintf(fp, "%s ", st[i].bi.dob);

        printf("********Previous Information********\n");

        printf("Enter SSC/O-Level info\n");

        printf("Enter name of institution:");
        scanf("%s",st[i].ssc.institution);
        fprintf(fp, "%s ", st[i].ssc.institution);
        printf("Enter exam year:");
        scanf("%d",&st[i].ssc.year_of_exam);
        fprintf(fp, "%d ", st[i].ssc.year_of_exam);
        printf("Enter Grade:");
        scanf("%d",&st[i].ssc.grade);
        fprintf(fp, "%d ",st[i].ssc.grade);

        printf("Enter HSC/O-Level info\n");

        printf("Enter name of institution:");
        scanf("%s",st[i].hsc.institution);
        fprintf(fp, "%s ", st[i].hsc.institution);
        printf("Enter exam year:");
        scanf("%d",&st[i].hsc.year_of_exam);
        fprintf(fp, "%d ", st[i].hsc.year_of_exam);
        printf("Enter Grade:");
        scanf("%d",&st[i].hsc.grade);
        fprintf(fp, "%d ", st[i].hsc.grade);

        printf("********NSU Information********\n");

        printf("Enter name of Department:");
        scanf("%s",st[i].ni.department);
        fprintf(fp, "%s ", st[i].ni.department);
        printf("Number of semester completed: ");
        scanf("%d",&st[i].ni.num_of_sem);
        fprintf(fp, "%d ", st[i].ni.num_of_sem);
        printf("Previous cgpa: ");
        scanf("%lf",&st[i].ni.prevcgpa);
        fprintf(fp, "%lf ", st[i].ni.prevcgpa);
        printf("Completed Credit: ");
        scanf("%d",&st[i].ni.credit_comp);
        fprintf(fp, "%d ", st[i].ni.credit_comp);

        printf("********Semester********\n");


        printf("Semester name: ");
        scanf("%s", st[i].ni.sem.semester_name);
        fprintf(fp, "%s ", st[i].ni.sem.semester_name);
        printf("number of courses:");
        scanf("%d", &st[i].ni.sem.num_of_course);
        fprintf(fp, "%d ", st[i].ni.sem.num_of_course);


        for(k=0; k<st[i].ni.sem.num_of_course; k++)
        {

            printf("Course Name:");
            scanf("%s", st[i].ni.sem.cou[k].course_name);
            fprintf(fp, "%s ", st[i].ni.sem.cou[k].course_name);
            fprintf(fp1, "%s ", st[i].ni.sem.cou[k].course_name);
            fprintf(fp2, "%s ", st[i].ni.sem.cou[k].course_name);
            printf("Faculty Name:");
            scanf("%s", st[i].ni.sem.cou[k].faculty_name);
            fprintf(fp, "%s ", st[i].ni.sem.cou[k].faculty_name);
            printf("Credit Number:");
            scanf("%d", &st[i].ni.sem.cou[k].credit);
            fprintf(fp, "%d ", st[i].ni.sem.cou[k].credit);

            printf("Quiz-1 Marks:");
            scanf("%lf",&q1);
            printf("Quiz-2 Marks:");
            scanf("%lf",&q2);
            printf("Quiz-3 Marks:");
            scanf("%lf",&q3);
            st[i].ni.sem.cou[k].ex.quiz=((q1+q2+q3)/3)*0.2;

            printf("Mid-1 Marks:");
            scanf("%lf",&m1);
            printf("Mid-2 Marks:");
            scanf("%lf",&m2);
            st[i].ni.sem.cou[k].ex.mid=((m1+m2)/2)*0.3;

            printf("Assignment Marks:");
            scanf("%lf",&as);
            st[i].ni.sem.cou[k].ex.assign=(as*0.2);

            printf("Final Marks:");
            scanf("%lf",&fin);
            st[i].ni.sem.cou[k].ex.fin=(fin*0.3);

            sum= (st[i].ni.sem.cou[k].ex.quiz) + (st[i].ni.sem.cou[k].ex.mid) + (st[i].ni.sem.cou[k].ex.assign) + (st[i].ni.sem.cou[k].ex.fin);

            if(sum>=93)
            {
                st[i].ni.sem.cou[k].ex.grade=4.0;
            }
            else if(sum>=90)
            {
                st[i].ni.sem.cou[k].ex.grade=3.7;
            }
            else if(sum>=87)
            {
                st[i].ni.sem.cou[k].ex.grade=3.3;
            }
            else if(sum>=83)
            {
                st[i].ni.sem.cou[k].ex.grade=3.0;
            }
            else if(sum>=80)
            {
                st[i].ni.sem.cou[k].ex.grade=2.7;
            }
            else if(sum>=77)
            {
                st[i].ni.sem.cou[k].ex.grade=2.3;
            }
            else if(sum>=74)
            {
                st[i].ni.sem.cou[k].ex.grade=2.0;
            }
            else if(sum>=70)
            {
                st[i].ni.sem.cou[k].ex.grade=1.7;
            }
            else if(sum>=67)
            {
                st[i].ni.sem.cou[k].ex.grade=1.3;
            }
            else if(sum>=60)
            {
                st[i].ni.sem.cou[k].ex.grade=1.0;
            }
            else
            {
                st[i].ni.sem.cou[k].ex.grade=0.0;
            }

            fprintf(fp, "%lf ", st[i].ni.sem.cou[k].ex.grade);
            fprintf(fp1, "%lf ", st[i].ni.sem.cou[k].ex.grade);

            new_cgpa=(st[i].ni.sem.cou[k].ex.grade*st[i].ni.sem.cou[k].credit+(st[i].ni.credit_comp*st[i].ni.prevcgpa))/(st[i].ni.sem.cou[k].credit+st[i].ni.credit_comp);
            st[i].ni.credit_comp+=st[i].ni.sem.cou[k].credit;
            st[i].ni.prevcgpa=new_cgpa;

        }
        fprintf(fp2,"%lf ", new_cgpa);
        fprintf(fp, "\n");
        fprintf(fp1, "\n");
        fprintf(fp2, "\n");
        getchar();
        printf("Do you want to input new student data? Y/N");
        char inp;
        scanf("%c",&inp);
        if(inp=='y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);

}




