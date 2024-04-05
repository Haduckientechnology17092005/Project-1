#include<bits/stdc++.h>

#include<iostream>

using namespace std;

struct Student
{
	string name, id;
	double GPA;
};

struct SV 
{
    Student s;
    SV *next;
};

typedef struct SV *sv;

//Cap phat dong moi voi du lieu la so nguyen x
//Khong typedef thi Node*tmp
sv makeNode()
{
    Student s;
    cout<<"Nhap thong tin sinh vien: \n";
    cout<<" Nhap ID: ";
    cin>>s.id;
    cout<<"Nhap ten: ";
    cin.ignore();
    getline(cin,s.name);
    cout<<"Nhap GPA: ";
    cin>>s.GPA;
    sv tmp = new SV();
    tmp->s = s;
    tmp->next = NULL;
    return tmp;
}

//Kiem tra rong
bool empty(sv a)
{
	return a == NULL;
}

//dem co bao nhieu phan tu
int Size (sv a)
{
	//duyet tu dau -> NULL 
	int cnt = 0;
	while (a != NULL)
	{
	++cnt;
	a = a->next; //gan dia chi cua not tiep thep cho node hien tai
	// cho node hien tai nhay sang not tiep theo
	}
	return cnt;
}

//Them 1 phan tu vao dau danh scah lien ket
void insert_First(sv &a)
{
    //Neu a rong gan a bang note
    sv tmp = makeNode();
    if(a==NULL)
    {
        a = tmp;
    }	
    else 
    {
        tmp->next = a;
        a = tmp;
        //dung thu tu
    }
}
//Khong typedef
// void insert_Last(node *a, int x)
// {
//     //Neu a rong gan a bang note
//     node tmp = makeNode(x);
//     if(*a==NULL)
//     {
//         *a = tmp;
//     }    
//     else 
//     {
//         tmp -> next = *a;
//         *a = tmp;
//     }
// }
void insert_Last(sv &a)
{
    sv tmp = makeNode();
    if(a==NULL)
    {
        a = tmp;
    }
    else 
    {
        sv p = a;
        while(p->next != NULL)//Neu a-> next != NULL -> bi mat het -> phai khoi tao nut khac bang a de duyet
        {
            p = p->next;
        }
        p->next = tmp;
    }
}
//Them 1 phan tu vao giua
void insert_Middle(sv &a, int pos)
{
    int n = Size(a);
    if(pos <= 0 || pos > n+1)
    {
        cout << "Vi tri chen khong hop le\n";
    }
    else if(n==1) 
    {
        insert_First(a);
    }
    else if(n==pos+1)
    {
        insert_Last(a);
    }
    else 
    {
        sv p = a;
        for(int i=1;i<pos-1;i++)
        {
            p = p->next;
        }
        sv tmp = makeNode();
        tmp->next = p->next;
        p->next = tmp;
    }
}
//Xoa phan tu dau
void delete_First(sv &a)
{
    if(a==NULL)
    return ;
    a = a->next;
}
//Xoa phan tu cuoi
void delete_Last(sv &a)
{
    if(a==NULL)
    return ;
    sv truoc = NULL;
    sv sau = a;
    while(sau->next!=NULL)
    {
        truoc = sau;
        sau = sau -> next;
        if(truoc==NULL)
        {
            a=NULL;
        }
        else 
        {
            truoc->next = NULL;
        }
    }
}
//Xoa o giua
void delete_Middle(sv &a, int pos)
{
    if(pos<=0 || pos>Size(a))
    return ;
    sv truoc = NULL;
    sv sau = a;
    for(int i=1;i<pos;i++)
    {
        truoc = sau;
        sau = sau -> next;
    }
    if(truoc==NULL)
    {
        a=a->next;
    }
    if(truoc != NULL)
    {
        truoc->next = sau->next;
    }
}

//In sinh vien
void print(Student s){
    cout<<"ID: "<<s.id<<"\n";
    cout<<"Name: "<<s.name<<"\n";
    cout<<"GPA: "<<fixed<<setprecision(2)<<s.GPA<<"\n";
}
//In danh sach
void print_list(sv a)
{
    cout<<"\n-------------DS Sinh vien-----------------\n";
    while(a!=NULL)
    {
        print(a->s);
        a = a->next;
    }
    cout<<"\n------------------------------\n";
}
//Sap xep
void arrange(sv &a)
{
    for(sv p = a; p-> next != NULL; p=p->next)
    {
        sv min =p;
        for(sv q = p; q != NULL; q=q->next)
        {
            if(q->s.GPA < min->s.GPA)
            {
                min = q;
            }
        }
        Student tmp = min -> s;
        min -> s = p->s;
        p->s = tmp;
    }
}

int main()
{
    sv head = NULL;
    while(1){
        cout<<"------------------------------\n";
        cout<<"1. Chen phan tu dau danh sach\n";
        cout<<"2. Chen phan tu cuoi\n";
        cout<<"3. Chen phan tu giua\n";
        cout<<"4. Xoa phan tu dau\n";
        cout<<"5. Xoa phan tu cuoi\n";
        cout<<"6. Xoa phan tu giua\n";
        cout<<"7. Duyet danh sach lien ket\n"; 
        cout<<"8. Sap xep danh sach lien ket\n";
        cout<<"0. Thoat khoi chuong trinh\n";
        cout<<"------------------------------\n";
        cout<<"Nhap lua chon\n";
        int lc;
        cin>>lc;
        if(lc==1){
            insert_First(head);
        } 
        else if(lc==2)
        {
            insert_Last(head);
        }
        else if(lc==3)
        {
            int pos;
            cout<<"Nhap vi tri can chen\n";
            cin>>pos;
            insert_Middle(head,pos);
        }
        else if(lc==4)
        {   
            delete_First(head);
        }
        else if(lc==5)
        {
            delete_Last(head);
        }
        else if(lc==6)
        {
            int pos;
            cout<<"Nhap vi tri can xoa\n";
            cin>>pos;
            delete_Middle(head,pos);
        }
        else if(lc==7)
        {
        	cout<<"\n";
            print_list(head);
            cout<<"\n";
        }
        else if(lc==8)
        {
            arrange(head);
            cout<<"\n";
            print_list(head);
            cout<<"\n";
        }
        else if(lc==0)
        {
            break;
        }
    }
	cout<<"Tam biet"<<"\n";
	return 0;
}
