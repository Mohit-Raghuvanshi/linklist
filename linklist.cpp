#include<iostream>
using namespace std;
 //singly circular linklist
struct __node
{
  int data;
  struct __node*next;
};
struct __node*__head=0;
 //doubly circular linklist
struct _node_
{
  struct _node_*pre;
  int data;
  struct _node_*next;
};
struct _node_*_head=0;
int __get()
{  
    int data;
    cout<<"enter data";
    cin>>data;
    return (data);
}
void _create_()  //doubly circular linklist
{
    struct _node_*ptr;
    ptr=new _node_;
    ptr->data=__get();
    ptr->pre=0;
    ptr->next=0;
    _head=ptr;
}
void _display_()  //doubly circular linklist
{
  if(_head->next==0)
  {
    cout<<_head->data;
  }
  else
  {
    struct _node_*ptr;
    ptr=_head;
    cout<<ptr->data;
    ptr=ptr->next;
    while(ptr!=_head)
    {
        cout<<" "<<ptr->data;
        ptr=ptr->next;
    }
  }
}
void insert_beg_()  //doubly circular linklist
{
    struct _node_*ptr;
    ptr=new _node_;
    ptr->data=__get();
    ptr->next=_head;
    if(_head->next==0)
    {
        _head->pre=ptr;
        _head->next=ptr;
        ptr->pre=_head;
    }
    else
    {
       ptr->next=_head;
       ptr->pre=_head->pre;
       (_head->pre)->next=ptr;
       _head->pre=ptr;
    }
    _head=ptr;
}
void insert_end_() //doubly circular linklist
{
  struct _node_*ptr;
  ptr=new _node_;
  ptr->data=__get();
  if(_head->next==0)
  {
    ptr->pre=_head;
    _head->next=ptr;
    _head->pre=ptr;
    ptr->next=_head;
  }
  else
      {
        struct _node_*temp;
        temp=_head;
        while(temp->next!=_head)
        {
          temp=temp->next;
        }
        ptr->pre=temp;
        ptr->next=temp->next;
        (temp->next)->pre=ptr->pre;
        temp->next=ptr;
      }
}
void _val_spec() //doubly circular linklist
{ 
  if(_head==0)
  {
    _create_(); //doubly circular linklist
  }
  else
  {
   int val;
   cout<<"enter value";
   cin>>val;
   if(val<_head->data)
   {
     insert_beg_(); //doubly circular linklist
   }
    else
   {
     if(_head->next==0)
     {
       insert_end_(); //doubly circular linklist
     }
     else
     {
        struct _node_*temp;
        temp=_head;
        while(temp->data<val&&temp->next!=0)
        {
          temp=temp->next;
         }
          if(temp->data>=val)
        {
          struct _node_*ptr;
          ptr=new _node_;
          ptr->data=val;
          ptr->pre=temp->pre;
          ptr->next=temp;
          (temp->pre)->next=ptr;
          temp->pre=ptr;
        }
         else
        {
          insert_end_(); //doubly circular linklist
        }
     }
   }
  
  }
}
void insert_pos_() //doubly circular linklist
{
  int count=1,pos;
  struct _node_*ptr;
  ptr=new _node_;
  cout<<"enter position";
  cin>>pos;
  if(pos==count)
  {
    insert_beg_(); //doubly circular linklist
  }
   else
  {
    if(pos<count)
    {
      cout<<"invalid position";
    }
    else
    {
      struct _node_*temp;
      temp=_head;
       while(count<pos&&temp->next!=0)
     {
       temp=temp->next;
       count++;
      }
       if(temp->next==0)
        {
          insert_end_(); //doubly circular linklist
        }
         else
       {
         ptr->data=__get();
         ptr->next=temp;
         (temp->pre)->next=ptr;
         ptr->pre=temp->pre;
         temp->pre=ptr;
        }
    }
  }
}
void delete_beginning_()//doubly circular linklist
{
    if((_head->next)->next==_head)
      {
        (_head->next)->next=0;
        _head=_head->next;
        delete (_head->pre);
        _head->pre=0;
      }
    else
      {
        struct _node_*ptr;
        ptr=_head;
        (_head->pre)->next=_head->next;
        (_head->next)->pre=_head->pre;
        _head=_head->next;
        delete ptr;
      }
}
void delete_end_() //doubly circular linklist
{
  struct _node_*temp;
  temp=_head->pre;
  _head->pre=temp->pre;
  (temp->pre)->next=_head;
  delete temp;
}
void delete_pos_() //doubly circular linklist
{
  int pos,count=1;
  cout<<"enter position";
  cin>>pos;
  if(pos==count)
  {
    delete_beginning_();
  }
  else
  {
    if(pos<count)
    {
      cout<<"invalid position";
    }
    else
    {
      struct _node_*temp;
      temp=_head;
       while(count<pos&&temp->next!=0)
     {
       temp=temp->next;
       count++;
     }
     if(temp->next==0)
     {
       delete_end_();
     }
      else
      {
        (temp->pre)->next=temp->next;
        (temp->next)->pre=temp->pre;
        delete temp;
      }
    }
  }
}
void delete_val_() //doubly circular linklist
{
  int val;
  cout<<"enter the value";
  cin>>val;
  if(_head->data==val)
  {
    delete_beginning_(); //doubly circular linklist
  }
  else
  {
  struct _node_*temp;
   temp=_head;
   while(temp->data!=val&&temp!=0)
   {
    temp=temp->next;
   }
   if(temp==0)
   {
    cout<<"invalid value";
   }
     else
   {
    if(temp->next==0)
    {
     delete_end_(); //doubly circular linklist
    }
     else
   {
     (temp->pre)->next=temp->next;
     (temp->next)->pre=temp->pre;
     delete temp;
    }
   }
  }
}
void __display() //singly circular linklist
{   
    struct __node*ptr;
    ptr=__head;
    cout<<ptr->data;
    ptr=ptr->next;
    while(ptr!=__head)
    {
        cout<<" "<<ptr->data;
        ptr=ptr->next;
    }
}
void __create() //singly circular linklist
{
struct __node*ptr;
ptr=new __node;
ptr->data=__get();
ptr->next=0;
__head=ptr;
}
void insert__beg()  //singly circular linklist
{
    if(__head->next==0)
    {
       struct __node*ptr;
        ptr=new __node;
        ptr->data=__get();
        ptr->next=__head;
        __head->next=ptr;
        __head=ptr;
    }
    else
        {    struct __node*ptr;
            struct __node*temp;
            ptr=new __node;
            temp=__head->next;
            ptr->data=__get();
            ptr->next=__head;
            while(temp->next!=__head)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            __head=ptr;
        }
}
void insert__end()  //singly circular linklist
{
    if(__head->next==0)
      {
        struct __node*temp;
        struct __node*ptr;
        temp=new __node;
        ptr=__head;
        temp->data=__get();
        while(ptr!=__head)
        {
        ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=__head;
      }
    else
        {
            struct __node*ptr;
            struct __node*temp;
            ptr=new __node;
            temp=__head->next;
            ptr->data=__get();
            ptr->next=__head;
            while(temp->next!=__head)
            {
                temp=temp->next;
            }
            temp->next=ptr;
        }
}
void insert_by_position() //singly circular linklist
{
  struct __node*temp;
  struct __node*ptr;
  temp=new __node;
  ptr=__head;
  int count=1,pos;
  cout<<"enter position";
  cin>>pos;
  if(count==pos)
  {
    insert__beg();  //singly circular linklist
  }
  else
  {
    if(pos<count)
    {
      cout<<"invalid position";
    }
    else
        {
          temp->data=__get();
            while(count<(pos-1))
            {
              ptr=ptr->next;
              count++;
            }
            temp->next=ptr->next;
            ptr->next=temp;
        }
  }
}
void insert_by_value()  //singly circular linklist
{
  struct __node*temp;
  struct __node*ptr;
  struct __node*trail;
  temp=new __node;
  ptr=__head;
  temp->data=__get(); //doubly circular linklist
  trail=0;
  if(temp->data<__head->data)
  {
    insert__beg();  //singly circular linklist
  }
  else
  {
  while(ptr->data<temp->data&&ptr->next!=0)
  {
    trail=ptr;
   ptr=ptr->next;
  }
  if(ptr->data>=temp->data)
  {
    temp->next=trail->next;
  trail->next=temp;
  }
  else
  {
   insert__end();  //singly circular linklist
  }
  }
}
void __begdel() //singly circular linklist
{
  struct __node*ptr;
  struct __node*temp;
  temp=__head->next;
  ptr=__head;
  __head=__head->next;
   while(temp->next!=ptr)
   {
    temp=temp->next;
   }
   temp->next=__head;
  delete ptr;
}
void __enddel() //singly circular linklist
{
  struct __node*temp;
  struct __node*trail;
  temp=__head;
  trail=0;
  if(temp->next==0)
  {
    delete temp;
    __head=0;
  }
  else{
  while(temp->next!=__head)
  {
   trail=temp;
   temp=temp->next; 
  }
  delete temp;
  trail->next=__head;
  }
}
void __valdel() //singly circular linklist
{
  struct __node*temp;
  struct __node*trail;
  int n;
  n=__get();
  if(n==__head->data)
  {
    __begdel(); //singly circular linklist
  }
  else
  {
    trail=0;
    temp=__head;
    
    while(temp->data!=n&&temp->next!=0)
    {
      trail=temp;
      temp=temp->next;
    }
    if(temp->next==0)
    {
      cout<<"not found";
    }
     else
    {
      if(temp->next==0)
      {
        __enddel(); //singly circular linklist
      }
      else
      {
        trail->next=temp->next;
        delete temp;
      }
    }
    
  }
}
void __posdel() //singly circular linklist
{

  struct __node*temp;
  struct __node*ptr;
  int n;
  cout<<"enter position";
  cin>>n;
  if(n==1)
  {
   __begdel(); //singly circular linklist
  }
  else{
     int c=1;
     ptr=0;
     temp=__head;
     while(c<n&&temp!=0)
     {
      ptr=temp;
      temp=temp->next;
      c++;
     }
     if(temp==0)
     {
      cout<<"invalid";
     }
     else{
      if(temp->next==0)
      {
         __enddel(); //singly circular linklist
      }
      else{
        ptr->next=temp->next;
        delete temp;
      }
     }
  }
}
//doubly linklist
struct _node
{
    struct _node*next;
    int data;
    struct _node*pre;
};
struct _node*_head_=0;
void _create() //doubly linklist
{
struct _node*ptr;
ptr=new _node;
ptr->data=__get();
ptr->next=0;
ptr->pre=0;
_head_=ptr;
}
void _beg() //doubly linklist
{
    struct _node*ptr;
    ptr=new _node;    
    ptr->data=__get();
    ptr->pre=0;
    ptr->next=_head_;
    _head_->pre=ptr;
    _head_->next=0;
    _head_=ptr;
}
void _display() //doubly linklist
{
  struct _node*ptr;
  ptr=_head_;
  while(ptr!=0)
  {
    cout<<" "<<ptr->data;
    ptr=ptr->next;
  }   
}
void _end() //doubly linklist
{
  struct _node*ptr;
  ptr=new _node;
  ptr->data=__get();
  struct _node*temp;
  temp=_head_;
  while(temp->next!=0)
  {
    temp=temp->next;
  }
  temp->next=ptr;
  ptr->pre=temp;
  ptr->next=0;
}
void _valspec() //doubly linklist
{ 
  if(_head_==0)
  {
    _create(); //doubly linklist
  }
  else
  {
   int val;
   cout<<"enter value";
   cin>>val;
   if(val<_head_->data)
   {
     _beg(); //doubly linklist
   }
    else
   {
     if(_head_->next==0)
     {
       _end(); //doubly linklist
     }
     else
     {
        struct _node*temp;
        temp=_head_;
        while(temp->data<val&&temp->next!=0)
        {
          temp=temp->next;
         }
          if(temp->data>=val)
        {
          struct _node*ptr;
          ptr=new _node;
          ptr->data=val;
          ptr->pre=temp->pre;
          ptr->next=temp;
          (temp->pre)->next=ptr;
          temp->pre=ptr;
        }
         else
        {
          _end(); //doubly linklist
        }
     }
   }
  
  }
}
void _pos() //doubly linklist
{
  int count=1,pos;
  struct _node*ptr;
  ptr=new _node;
  cout<<"enter position";
  cin>>pos;
  if(pos==count)
  {
    _beg(); //doubly linklist
  }
   else
  {
    if(pos<count)
    {
      cout<<"invalid position";
    }
    else
    {
      struct _node*temp;
      temp=_head_;
       while(count<pos&&temp->next!=0)
     {
       temp=temp->next;
       count++;
      }
       if(temp->next==0)
        {
          _end(); //doubly linklist
        }
         else
       {
         ptr->data=__get();
         ptr->next=temp;
         (temp->pre)->next=ptr;
         ptr->pre=temp->pre;
         temp->pre=ptr;
        }
    }
  }
}
void _beg_del() //doubly linklist
{
  _head_=_head_->next;
  delete(_head_->pre);
  _head_->pre=0;
}
void _end_del() //doubly linklist
{
   struct _node*temp;
   temp=_head_;
   if(temp->next==0)
   {
     delete temp;
     _head_=0;
   }
    else
   {
     while(temp->next!=0)
     {
       temp=temp->next;
     }
      (temp->pre)->next=0;
      delete temp;
    }
}
void _pos_del() //doubly linklist
{
  int pos,count=1;
  cout<<"enter position";
  cin>>pos;
  if(pos==count)
  {
    _beg_del(); //doubly linklist
  }
  else
  {
    if(pos<count)
    {
      cout<<"invalid position";
    }
    else
    {
      struct _node*temp;
      temp=_head_;
       while(count<pos&&temp->next!=0)
     {
       temp=temp->next;
       count++;
     }
     if(temp->next==0)
     {
       _end_del(); //doubly linklist
     }
      else
      {
        (temp->pre)->next=temp->next;
        (temp->next)->pre=temp->pre;
        delete temp;
      }
    }
  }
}
void _val_del() //doubly linklist
{
  int val;
  cout<<"enter the value";
  cin>>val;
  if(_head_->data==val)
  {
    _beg_del(); //doubly linklist
  }
  else
  {
  struct _node*temp;
   temp=_head_;
   while(temp->data!=val&&temp!=0)
   {
    temp=temp->next;
   }
   if(temp==0)
   {
    cout<<"invalid value";
   }
     else
   {
    if(temp->next==0)
    {
     _end_del(); //doubly linklist
    }
     else
   {
     (temp->pre)->next=temp->next;
     (temp->next)->pre=temp->pre;
     delete temp;
    }
   }
  }
}
//singly linklist
struct node
{
    int data;
    struct node*next;
} ;
struct node*head=0;
void create()//singly linklist
{
    struct node*temp;
    int d;
    cout<<"enter any number";
    cin>>d;
    temp=new node;
    temp->data=d;
    temp->next=0;
    head=temp;
} 
void display() //singly linklist
{
  struct node*ptr;
  ptr=head;
  while(ptr!=0)
  {
    cout<<" "<<ptr->data;
    ptr=ptr->next;
  }   
}
void beg() //singly linklist
{
  struct node*p;
  p=new node;
  p->data=__get();
  p->next=head;
  head=p;
}
void end() //singly linklist
{
  struct node*temp;
  struct node*ptr;
  temp=new node;
  ptr=head;
  temp->data=__get();
  while(ptr->next!=0)
  {
   ptr=ptr->next;
  }
  ptr->next=temp;
  temp->next=0;
}
void pos() //singly linklist
{
  struct node*temp;
  struct node*ptr;
  temp=new node;
  ptr=head;
  int c=1,d;
  cout<<"enter position";
  cin>>d;
  if(c==d)
  {
    beg();
  }
  else
  {
    if(d<c)
    {
      cout<<"invalid position";
    }
  temp->data=__get();
    while(c<(d-1))
    {
      ptr=ptr->next;
      c++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
  }
}
void value()
{
  struct node*temp;
  struct node*ptr;
  struct node*trail;
  temp=new node;
  ptr=head;
  temp->data=__get();
  trail=0;
  if(temp->data<head->data)
  {
    beg();
  }
  else
  {
  while(ptr->data<temp->data&&ptr->next!=0)
  {
    trail=ptr;
   ptr=ptr->next;
  }
  if(ptr->data>=temp->data)
  {
    temp->next=trail->next;
  trail->next=temp;
  }
  else
  {
   end();
  }
  }
}
void begdel()
{
  struct node*ptr;
  ptr=head;
  head=head->next;
  delete ptr;
}
void enddel()
{
  struct node*temp;
  struct node*trail;
  temp=head;
  trail=0;
  if(temp->next==0)
  {
    delete temp;
    head=0;
  }
  else{
  while(temp->next!=0)
  {
   trail=temp;
   temp=temp->next; 
  }
  delete temp;
  trail->next=0;
  }
}
void middel()
{
  struct node*temp;
  struct node*trail;
  int n;
  n=__get();
  if(n==head->data)
  {
    begdel();
  }
  else
  {
    trail=0;
    temp=head;
    
    while(temp->data!=n&&temp->next!=0)
    {
      trail=temp;
      temp=temp->next;
    }
    if(temp->next==0)
    {
      cout<<"not found";
    }
     else
    {
      if(temp->next==0)
      {
    enddel();
      }
      else
      {
        trail->next=temp->next;
        delete temp;
      }
    }
    
  }
}
void posdel()
{

  struct node*temp;
  struct node*ptr;
  int n;
  n=__get();
  if(n==1)
  {
   begdel();
  }
  else{
     int c=1;
     ptr=0;
     temp=head;
     while(c<n&&temp!=0)
     {
      ptr=temp;
      temp=temp->next;
      c++;
     }
     if(temp==0)
     {
      cout<<"invalid";
     }
     else{
      if(temp->next==0)
      {
        enddel();
      }
      else{
        ptr->next=temp->next;
        delete temp;
      }
     }
  }
}
int main()
{
   int n;
   do
   {
   cout<<"\nenter\n1.singly linklist\n2.doubly linklist\n3.circular linklist";
   cin>>n;
     switch(n)
     {
       case 1: 
              {
                int a;
do{ 
    cout<<"1.create\n2.display\n3.insert\n4.delete";//singly linklist
    cin>>a;
    switch(a)
   {case 1:
   { 
            create();
            break;
   }
   case 2:
    {
               display();
           break;
    }
    case 3:
          {
            cout<<"1.beginning\n2.end\n3.specified"; //singly linklist
            cin>>a;
            switch(a)
            {
              case 1:
              {
                beg();
                break;
              }
              case 2:
              {
                end();
                break;
              }
              case 3:
              {
                cout<<"1.position\n2.value"; //singly linklist
                cin>>a;
                switch(a)
                    {
                      case 1:
                          {
                            pos();
                            break;
                          }
                      case 2:
                          {
                            if(head==0)
                            {
                              create();
                            }
                            else
                            {
                             value();
                             break;
                            }
                          }    
                    }
                    break;
              }
            }
            break;
          }
     case 4:
     {
      if(head==0)
      {
        cout<<"invalid operation";
      }
      else
      {
        if(head->next==0)
                       {
                        struct node*ptr;
                        ptr=head;
                        delete ptr;
                        head=0;
                       }
           else
           {
      cout<<"1.beginning\n2.specified\n3.end"; //singly linklist
      cin>>a;
      switch(a)
      {
        case 1:
        {
            begdel();
          break;
        }
        case 2:
        {
          cout<<"1.value\n2.position"; //singly linklist
          cin>>a;
          if(a==1)
          {
           middel();
         break;
          }
          if(a==2)
          {
            posdel();
            break;
          }  
        }
        case 3:
        {
          enddel();
         break;
        }
        break;
      }
      }
     }
     break;
     }
   }
   cout<<"\ndo you want to continue press\n 1.yes\n2.no"; //singly linklist
   cin>>a;
  }while(a!=2||a!=2);
                break;
              }
      case 2: //doubly linklist
             {
                 int b;
    do
    {
    cout<<" \n1.create\n2.insert\n3.display\n4.Delete"; //doubly linklist
    cin>>b;
    switch(b)
    {
        case 1:
              {
                _create();
                break;
              }
        case 2:
              { 
                cout<<"\n1.insert at begining\n2.insert at specified\n3.insert at end"; //doubly linklist
                cin>>b;
                switch (b)
                {
                  case 1:
                       {
                        if(head==0)
                        {
                          _create();
                        }
                        else{
                         _beg();
                        }
                        break;
                       }
                  case 2:
                        { 
                          cout<<"\n1.By value\n2.By position"; //doubly linklist
                          cin>>b;
                          switch(b)
                          {
                            case 1:
                                   {
                                     _valspec();
                                     break;
                                   }
                            case 2:
                                   {
                                     _pos();
                                     break;
                                   }
                          } 
                          break;
                        }       
                  case 3:
                         {
                          if(head==0)
                          {
                            _create();
                          }
                          else
                          {
                           _end();
                          }
                          break;
                         }      
                }
                break;
              }
        case 3:
               {
                _display();
                break;
               }
        case 4:
              {
                if(_head_==0)
                {
                  cout<<"invalid operation";
                }
                else
                {
                   if(_head_->next==0)
                       {
                        struct _node*ptr;
                        ptr=_head_;
                        delete ptr;
                        _head_=0;
                       }
                       else
                       {
                cout<<"\n1.begining\n2.specified\n3.end"; //doubly linklist
                cin>>b;
                switch(b)
                {
                  case 1:
                  {
                         _beg_del();
                    break;
                  }
                  case 2:
                  { 
                            cout<<"\n1.position\n2.value"; //doubly linklist
                            cin>>b;
                            switch(b)
                            {
                              case 1:
                              {
                                _pos_del();
                                break;
                              }
                              case 2:
                              {
                                _val_del();
                              break;
                              }
                            }
                          
                    break;
                  }
                  case 3:
                  {
                         _end_del();
                    break;
                  }
                }
                       }
              }  
              break;
            }     
    }
    cout<<"\ndo you want to continue doubly linklist\n1.no\n2.yes"; //doubly linklist
    cin>>b;
    }while(b!=1); //doubly linklist
                break;
             }
       case 3: //circular linklist
              {
                int n;
    do
{
    cout<<"enter\n1.singly circular\n2.doubly circular"; //circular linklist
    cin>>n;
    switch (n)
    {
    case 1:
           {
            cout<<"\nenter\n1.create\n2.insert\n3.display\n4.delete"; //singly circular linklist
            cin>>n;
            switch(n)
            {
                case 1:
                       {
                        __create();
                        break;
                       }
                case 2:
                       {
                        cout<<"\nenter1.begining\n2.end\n3.specified"; //singly circular linklist
                        cin>>n;
                        switch(n)
                        {
                            case 1:
                                   {
                                      if(head==0)
                                      {
                                        __create();
                                        break;
                                      }
                                      else
                                      {
                                          insert__beg();
                                          break;
                                      }
                                   }
                            case 2:
                                   {
                                    insert__end();
                                    break;
                                   }
                            case 3:
                                   {
                                    cout<<"\n1.insert_by_value\n2.insert_by_position"; //singly circular linklist
                                    cin>>n;
                                    switch(n)
                                             {
                                                case 1:
                                                      {
                                                        insert_by_value();
                                                        break;
                                                      }
                                                case 2:
                                                       {
                                                         insert_by_position();
                                                         break;
                                                       }
                                                       break;
                                             }
                                   }
                        }
                        break;
                       }
                case 3: //singly circular linklist
                       {
                        __display();
                        break;
                       }
                case 4://singly circular linklist
                       {
                              if(__head==0)
                              {
                                cout<<"invalid position";
                              }
                              else
                              {
                                 if(__head->next==0)
                                            {
                                            struct __node*ptr;
                                            ptr=__head;
                                            delete ptr;
                                              __head=0;
                                            }
                                          else
                                            {
                                cout<<"\nenter\n1.begining\n2.end\n3.specified"; //singly circular linklist
                                cin>>n;
                                switch(n)
                                {
                                  case 1://singly circular linklist
                                       {
                                            __begdel();
                                          break;
                                        }
                                  case 2://singly circular linklist
                                        {
                                              __enddel();
                                          break;
                                        }
                                  case 3://singly circular linklist
                                        {
                                              cout<<"\nenter\n1.value\n2.position"; //singly circular linklist
                                              cin>>n;
                                              switch(n)
                                              {
                                                case 1:
                                                      {
                                                        __valdel();;
                                                        break;
                                                      }
                                                case 2:
                                                      {
                                                        __posdel();
                                                        break;
                                                      }
                                              }
                                            }
                                          break;
                                        
                                }
                                break;
                              }
                              }
                       }
                      break;
                    }
              break;
            }
      case 2:
            cout<<"\nenter\n1.create\n2.insert\n3.display\n4.delete"; //doubly circular linklist
              cin>>n;
              switch(n)
              {
                  case 1:
                        {
                          _create_();
                          break;
                        }
                  case 2:
                        { 
                          cout<<"\nenter\n1.begining\n2.end\n3.specified"; //doubly circular linklist
                          cin>>n;
                          switch(n)
                          { 
                            case 1: //doubly circular linklist
                                    {
                                      if(_head==0)
                                      {
                                        _create_();
                                      }
                                      else
                                      {
                                        insert_beg_();
                                      }
                                      break;
                                    }
                            case 2: //doubly circular linklist
                                  {
                                    if(_head==0)
                                      {
                                        _create_();
                                      }
                                      else
                                      {
                                        insert_end_();
                                      }
                                      break;
                                  }
                          case 3:
                                {
                                  cout<<"\nenter\n1.insert by value\n2.insert by position"; //doubly circular linklist
                                  cin>>n;
                                  switch(n)
                                  {
                                    case 1: //doubly circular linklist
                                           {
                                            if(_head==0)
                                              {
                                                _create_();
                                              }
                                              else
                                              {
                                                _val_spec();
                                              }
                                              break;
                                           }
                                    case 2: //doubly circular linklist
                                           {
                                             if(_head==0)
                                              {
                                                _create_();
                                              }
                                              else
                                              {
                                                insert_pos_();
                                              }
                                              break;
                                           }
                                  }
                                  break;
                                }
                        }
                        break;
                       }
                case 3:
                       {
                        _display_();
                        break;
                       }
                case 4://doubly circular linklist
                       {
                        if(_head==0)
                        {
                          cout<<"invalid operation";
                        }
                        else
                        {
                          if(_head->next==0)
                                              {
                                                struct _node_*ptr;
                                                ptr=_head;
                                                delete ptr;
                                                _head=0;
                                              }
                                              else
                                              {
                            cout<<"\nenter\n1.beginning\n2.end\n3.specified"; //doubly circular linklist
                            cin>>n;
                            switch(n)
                                    {
                                      case 1: //doubly circular linklist
                                            {
                                              delete_beginning_();
                                              break;
                                            }
                                      case 2: //doubly circular linklist
                                            {
                                              delete_end_();
                                              break;
                                            }      
                                      case 3:
                                            {
                                              cout<<"\nenter \n1.value\n2.position"; //doubly circular linklist
                                              cin>>n;
                                              switch(n)
                                              {
                                                case 1:
                                                        {
                                                          delete_val_(); //doubly circular linklist
                                                          break;
                                                        }      
                                                 case 2:
                                                        {
                                                          delete_pos_(); //doubly circular linklist
                                                          break;
                                                        }      
                                              }
                                              break;
                                            }
                                    }
                                    }
                        }
                          break;
                       }
            }
        break;
    }
    cout<<"\ndo you want to continue circular linklist\n1.yes\n2.no";
    cin>>n;
}while(n!=2); //circular linklist
                break;
              }
     }
       cout<<"do you want to continue linklist\n1.yes\n2.no";
       cin>>n;
    }while(n!=2);
    return 0;
}
