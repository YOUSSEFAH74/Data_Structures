#include <bits/stdc++.h>
using namespace std;
class Array
{
private:
    int size;
    int length;
    int *ptr;
public:
    Array(int arrsize)
    {
        size=arrsize;
        length=0;
        ptr=new int[arrsize];
    }
    void fill()
    {
        cout<<"How many items you want to fill:\n";
        int number_of_items;
        cin>>number_of_items;
        if(number_of_items>size)
        {
           cout<<"You cannot exceed the arrar size:\n";
           return;
        }
        else{
            for(int i=0;i<number_of_items;i++)
            {
                cout<<"Enter item number:\n";
                cin>>ptr[i];
                length++;
            }
        }
    }
    void Display()
    {
        cout<<"Display array content:\n";
        for(int i=0;i<length;i++)
        {
            cout<<ptr[i]<<"\t";
        }
        cout<<"\n";
    }
    int get_size()
    {
        return size;
    }
    int get_length()
    {
        return length;
    }
    int search(int key)
    {
        int index=-1;
        for(int i=0;i<length;i++)
        {
            if(ptr[i]==key)
            {
                index=i;
                break;
            }
            return index;
        }
    }
    void Append(int new_item)
    {
        if(length>size)
        {
            ptr[length]=new_item;
            length++;
        }
        else
        {
            cout<<"Error array is full\n";
        }
    }
    int insert(int index,int newitem)
    {
        if(index>=0&&index<size)
        {
            for(int i=length;i>index;--i)
            {
                ptr[i]=ptr[i-1];
            }
            ptr[index]=newitem;
            length++;
        }
        else
        {
            cout<<"idex out of range:\n";
        }
    }
};

int main() {
    cout<<"Enter the array size:\n";
    int x;
    cin>>x;
    Array Myarray(x);
    Myarray.fill();
    Myarray.Display();
    cout<<"array size: "<<Myarray.get_size()<<"length of array "<<Myarray.get_length()<<"\n";
    cout<<"enter the value to search for\n";
    int key;
    cin>>key;
    int index = Myarray.search(key);
    if(index==-1)
    {
      cout<<"item not found:\n";
    }
     else
     {
      cout<<"item found in position "<<index<<"\n";
     }
     //cout<<"enter new item to array:\n";
     cout<<"enter index and item:\n";
     int new_item;
     cin>>index>>new_item;
    Myarray.insert(index,new_item);
    Myarray.Display();
    cout<<"array size: "<<Myarray.get_size()<<" length of array: "<<Myarray.get_length()<<"\n";
    Myarray.Display();
     return 0;
}
