/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct stud 
{
    int rno;
    struct stud *lp,*rp;
};
FILE *fp;



struct stud *cr_node(int val)
{
    struct stud *new1=(struct stud*)malloc(sizeof(struct stud));
    new1->rno=val;
    new1->rp=NULL;
    new1->lp=NULL;
    return new1;
}
struct stud *ins(int val,struct stud *root)
{
    if(root==NULL)
    {
        root=cr_node(val);
    }
    else if (val<root->rno)
    {
        root->lp=ins(val,root->lp);
    }
    else if (val>root->rno)
    {
        root->rp=ins(val,root->rp);
    }
    else 
    {
        printf("\nDuplicate value not allowed ");
    }
    return root;
}
void inorder(struct stud *root)
{
    if(root!=NULL)
    {
        inorder(root->lp);
        printf("%d ",root->rno);
        fprintf(fp,"%d ",root->rno);
        inorder(root->rp);
    }
}
void postorder(struct stud *root)
{
    if(root!=NULL)
    {
        postorder(root->lp);
        postorder(root->rp);
        printf("%d ",root->rno);
        
    }
}
void preorder(struct stud *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->rno);
        preorder(root->lp);
        preorder(root->rp);
    }
}
void search (int val,struct stud *root)
{
    if(root!=NULL)
    {
        if(val==root->rno)
        {
            printf("\nData is found ..");
        }
        else if (val<root->rno)
        {
            search(val,root->lp);
        }
        else if (val>root->rno)
        {
            search(val,root->rp);
        }
        else 
        {
            printf("\nData is not found ...");
        }
    }
}
struct stud *del(int val,struct stud *root)
{
    if(root==NULL)
    {
        printf("\ntree is empty");
        return NULL;
    }
    else if (val<root->rno)
    {
        root->lp=del(val,root->lp);
    }
    else if (val>root->rno)
    {
        root->rp=del(val,root->rp);
    }
    else 
    {
        if(root->lp==NULL && root->rp==NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->lp!=NULL && root->rp==NULL)
        {
            struct stud *temp;
            temp=root->lp;
            free(root);
            return temp;
        }
        else if (root->lp==NULL && root->rp != NULL)
        {
            struct stud *temp ;
            temp=root->rp;
            free(root);
            return temp;
        }
        else 
        {
            struct stud *temp;
            temp=root->rp;
            while(temp->lp!=NULL)
            {
                temp=temp->lp;
            }
            root->rno=temp->rno;
            root->rp=del(temp->rno,temp->rp);
            
        }
    }
    return root;
}

struct stud *update(int val,struct stud *root)
{
    int n;
    if(val==root->rno)
    {
        printf("Enter a valid number:");
        scanf("%d",&n);
        root=del(val,root);
        root=ins(n,root);
        printf("\nUpdate successfully");
        
    }
    else if (val<root->rno)
    {
        root->lp=update(val,root->lp);
    }
    else if (val>root->rno)
    {
        root->rp=update(val,root->rp);
    }
    else 
    {
        printf("\nData is not found ...");
    }
    return root;
}
void in_orderfile()
{
    int n;
    printf("\nPrint inorder file data ..."); 
    while (fscanf(fp,"%d",&n)!=EOF)
    {
        printf("%d ",n);
    }
    
}
int main()
{
    struct stud *root=NULL;
    
    int ch,val;
    while(1)
    {
        printf("Enter your choice :\n1-->insert \n2-->in _order\n3-->pre_order\n4->post_order\n5-->search\n6-->update\n7-->delete\n8-->exit\n9-->file print data\nEntrer :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter student roll number :");
                scanf("%d",&val);
                root=ins(val,root);
                break;
            case 2:
            fp=fopen("inorder.txt","w");
                inorder(root);
                fclose(fp);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("\nEnter value for data search ...");
                scanf("%d",&val);
                search(val,root);break;
            case 6:
                printf("\nEnter value for data update ...");
                scanf("%d",&val);
                root=update(val,root);
                break;
     
            case 7:
                printf("\nEnter value for data delete ...");
                scanf("%d",&val);
                root=del(val,root);break;

            case 8:
                exit(0);
                break;
            case 9:
            fp=fopen("inorder.txt","r");
                in_orderfile();
                fclose(fp);
                break;
            default :
                printf("\nPlease Enter a valid choice :");
                break;
        }
        
    }
    

    return 0;
}