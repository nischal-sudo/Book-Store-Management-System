#include <stdio.h> 
#include <conio.h> 
#include <bits/stdc++.h> 
#include <fstream> 
#include <string.h> 
#include <iomanip>
#include <iostream> 
#include <sstream> 
#define TABLE_SIZE 300 
#define PRIME 139 
using namespace std; 
char bookItem[10], bookType[10], bookPrice[10]; string bookId; 
int key; 
int curr_size; 
int *hashTable; 
string value[TABLE_SIZE][100]; 
class Items 
{ 
public: 
 void AddItems(); 
 void DeleteItems(); 
 void SearchItem();
 void DisplayItem(); 
 void InsertIndex(int Index, int key, string TypeOfbook);  void LinearProbing(int key, string bookId, int Index, string TypeOfbook);  void SecondHash(int key, string bookId, int Index, string TypeOfbook);  void bookItemInsert(string bookId, string TypeOfbook);  void SaveHashTable(); 
 void ReadHashTable(); 
 void check(string bookId, int start, int ends, string book); }; 
bool isFull() 
{ 
 return (curr_size == TABLE_SIZE); 
} 
int hash1(int key) 
{ 
 return (key % TABLE_SIZE); 
} 
int hash2(int key) 
{ 
 return (PRIME - (key % PRIME)); 
}
void Items::LinearProbing(int key, string bookId, int Index, string TypeOfbook) { 
 int i; 
 Items k; 
 int start = Index; 
 for(i = Index; i < TABLE_SIZE;) 
 { 
 if(hashTable[i] == -1) 
 { 
 value[i][0] = bookId; 
 k.InsertIndex(i, key, TypeOfbook); 
 break; 
 } 
 i++; 
 if(i == TABLE_SIZE) 
 { 
 int j; 
 for(j = 0; j<start; j++) 
 { 
 value[j][0] = bookId; 
 k.InsertIndex(j, key, TypeOfbook); 
 break; 
 } 
 } 
 }
 cout<<"\n Linear probing is done to insert!!\n"; 
}; 
void Items::SecondHash(int key,string bookId, int Index, string TypeOfbook) { 
 Items k; 
 int index2 = hash2(key); 
 int i = 1; 
 while (1) 
 { 
 int newIndex = (Index + i * index2) % TABLE_SIZE; 
 if (hashTable[newIndex] == -1) 
 { 
 value[newIndex][0] = bookId; 
 k.InsertIndex(newIndex, key, TypeOfbook); 
 break; 
 } 
 i++; 
 } 
 cout<<"\n Second Hash is done to insert!!\n"; 
}; 
void Items::bookItemInsert(string bookId, string TypeOdbook) {
 Items k; 
 if(isFull()) 
 { 
 cout<<"\n Table is full!!"; 
 return; 
 } 
 int key = 0; 
 for(int x = 0; bookId[x] != '\0'; x++) 
 { 
 key += int(bookId[x]); 
 } 
 key = key/299; 
 int Index = hash1(key); 
 if (hashTable[Index] != -1) 
 { 
 int collisionchoice; 
 cout<<"\n.....Collision occurred....."; 
 cout<<"\n --> 1. LinearProbing"; 
 cout<<"\n --> 2. Second Hash"; 
 cout<<"\n............................\n"; 
 cout<<"\n Enter your method you want to insert: ";  cin>>collisionchoice; 
 switch(collisionchoice)
 { 
 case 1 : k.LinearProbing(key, bookId, Index, TypeOdbook);  break; 
 case 2 : k.SecondHash(key, bookId, Index, TypeOdbook);  break; 
 } 
 } 
 else 
 { 
 value[Index][0] = bookId; 
 k.InsertIndex(Index, key, TypeOdbook); 
 } 
 curr_size++; 
}; 
void Items::check(string bookId, int start, int ends, string book) { 
 string x = bookId; 
 int b = atoi(x.c_str()); 
 Items k; 
 int flag = 1; 
 for(int i = 0; i <TABLE_SIZE; i++) 
 { 
 if(b == hashTable[i]) 
 {
 flag = 0; 
 } 
 } 
 if(flag == 1) 
 { 
 if(b >= start && b < ends) 
 { 
 k.bookItemInsert(bookId, book); 
 } 
 else 
 { 
 cout<<"\n Invalid bookID and is not between "<<start<<" and "<<ends<<" \n";  } 
 } 
 else 
 { 
 cout<<"\n book ID already exists\n"; 
 } 
}; 
void Items::AddItems() 
{ 
 Items k; 
 int bookItemChoice;
 cout<<"\n .....Type of book items....."; 
 cout<<"\n 1. Science book"; 
 cout<<"\n 2. Economic book"; 
 cout<<"\n 3. Psychology book"; 
 cout<<"\n 4. Politics book"; 
 cout<<"\n ............................\n"; 
 cout<<"\n Enter the type of book item: ";  cin>>bookItemChoice; 
 if(bookItemChoice == 1) 
 { 
 cout<<"\n Enter the book id between (0 to 99): ";  cin>>bookId; 
 k.check(bookId, 0, 100, "Science_Book");  } 
 else if(bookItemChoice == 2) 
 { 
 cout<<"\n Enter the book id between (100 to 199): ";  cin>>bookId; 
 k.check(bookId, 100, 200, "Economic_Book");  } 
 else if(bookItemChoice == 3) 
 { 
 cout<<"\n Enter the book id between (200 to 299): ";  cin>>bookId;
 k.check(bookId, 200, 300, "Psychology_Book");  } 
 else if(bookItemChoice == 4) 
 { 
 cout<<"\n Enter the book id between (300 to 399): ";  cin>>bookId; 
 k.check(bookId, 300, 400, "Politics_book");  } 
}; 
void Items::InsertIndex(int Index, int key, string TypeOfbook) { 
 Items k; 
 string s = value[Index][0]; 
 stringstream geek(s); 
 geek >> hashTable[Index]; 
 cout<<"\n Enter the book type: "; 
 cout<<"\n >>>> 1. Fiction"; 
 cout<<"\n >>>> 2. Non-Fiction"; 
 cout<<"\n enter your choice: "; 
 int bookTypeChoice; 
 cin>>bookTypeChoice; 
 switch(bookTypeChoice) 
 { 
 case 1 : value[Index][2] = "Fiction";
 break; 
 case 2 : value[Index][2] = "Non-Fiction";  break; 
 } 
 cout<<"\n Enter the book name: "; 
 cin>>bookItem; 
 cout<<"\n Enter the book price: "; 
 cin>>bookPrice; 
 value[Index][1] = bookItem; 
 value[Index][3] = bookPrice; 
 cout<<"\n book Item inserted.\n"; 
 k.SaveHashTable(); 
 return; 
}; 
void Items::DeleteItems() 
{ 
 Items k; 
 cout<<"\n Enter the book ID you want to Delete: ";  cin>>bookId; 
 int flag = 0; 
 for(int i=0; i < TABLE_SIZE; i++) 
 { 
 if(value[i][0] == bookId) 
 {
 flag = 1; 
 hashTable[i] = -1; 
 value[i][0] = ""; 
 value[i][1] = ""; 
 value[i][2] = ""; 
 value[i][3] = ""; 
 value[i][4] = ""; 
 k.SaveHashTable(); 
 cout<<"\n book item deleted!!!\n";  } 
 } 
 if(flag == 0) 
 { 
 cout<<"\n book ID not found!!!\n";  } 
}; 
void Items::SearchItem() 
{ 
 Items k; 
 int optionId, referenceID, i; 
 int modifyChoice; 
 int flag = 0; 
 int id;
 string ys; 
 cout<<"\n Enter the book ID you want the details: ";  cin>>optionId; 
 for(i = 0; i < TABLE_SIZE; i++) 
 { 
 string s = value[i][0]; 
 stringstream geek(s); 
 geek >> referenceID; 
 if(referenceID == optionId) 
 { 
 flag = 1; 
 id = i; 
 break; 
 } 
 } 
 if(flag == 0) 
 { 
 cout<<"\n book ID not found!!\n"; 
 } 
 else 
 { 
 cout<<"\n >>>>>> bookID : "<<value[id][0];  cout<<"\n >>>>>> book Name : "<<value[id][1];  cout<<"\n >>>>>> book Type : "<<value[id][2];  cout<<"\n >>>>>> book Price: "<<value[id][3];
 cout<<"\n book ID found!!!\n"; 
 cout<<"\n Want to modify any item (y/n): ";  cin>>ys; 
 if(ys == "y") 
 { 
 do 
 { 
 cout<<"\n -------Modify Items-----";  cout<<"\n 1. book Name"; 
 cout<<"\n 2. book Type"; 
 cout<<"\n 3. book price"; 
 cout<<"\n 4. Exit"; 
 cout<<"\n ------------------------\n";  cout<<"\n Enter your choice to modify: ";  cin>>modifyChoice; 
 switch(modifyChoice) 
 { 
 case 1 : cout<<"\n Enter the name: ";  cin>>bookItem; 
 value[id][1] = bookItem;  cout<<"\n book name modified!!!\n";  break; 
 case 2 : cout<<"\n Enter the book type: ";  cout<<"\n >>>> 1. Fiction";  cout<<"\n >>>> 2. Non-Fiction";
 cout<<"\n Enter your choice: ";  int bookTypeChoice; 
 cin>>bookTypeChoice; 
 switch(bookTypeChoice)  { 
 case 1 : value[id][2] = "Fiction";  break; 
 case 2 : value[id][2] = "Non-Fiction";  break; 
 } 
 cout<<"\n book type modified!!!\n";  break; 
 case 3 : cout<<"\n Enter book Price: " ;  cin>>bookPrice; 
 value[id][3] = bookPrice;  cout<<"\n book price modified!!!\n";  break; 
 case 4 : modifyChoice = 5; 
 } 
 k.SaveHashTable(); 
 }while(modifyChoice < 4); 
 }
 else 
 { 
 cout<<"\n Thanks for Displaying all details!!!\n";  } 
 } 
}; 
void Items::DisplayItem() 
{ 
 Items k; 
 string ys; 
 int bookItemChoice, i; 
 cout<<"\n .....Type of book items....."; 
 cout<<"\n 1. Science book"; 
 cout<<"\n 2. Economics book"; 
 cout<<"\n 3. Psychology book"; 
 cout<<"\n 4. Politics book"; 
 cout<<"\n ............................\n"; 
 cout<<"\n Enter the type of book item you want to display: ";  cin>>bookItemChoice; 
 cout<<"\n ----------HashTable----------"; 
 cout<<"\n | Address | book ID |"; 
 cout<<"\n -----------------------------";
 if(bookItemChoice == 1) 
 { 
 for(i = 0; i < TABLE_SIZE; i++) 
 { 
 if (hashTable[i] >= 0 && hashTable[i] <99)  cout <<"\n |\t"<<i<<"\t|\t"<<hashTable[i]<<"\t|";  } 
 } 
 if(bookItemChoice == 2) 
 { 
 for(i = 0; i <= TABLE_SIZE; i++) 
 { 
 if (hashTable[i] >= 100 && hashTable[i] < 199)  cout <<"\n |\t"<<i<<"\t|\t"<<hashTable[i]<<"\t|";  } 
 } 
 if(bookItemChoice == 3) 
 { 
 for(i = 0; i < TABLE_SIZE; i++) 
 { 
 if (hashTable[i] >= 200 && hashTable[i] < 299)  cout <<"\n |\t"<<i<<"\t|\t"<<hashTable[i]<<"\t|";  }
 } 
 if(bookItemChoice == 4) 
 { 
 for(i = 0; i < TABLE_SIZE; i++) 
 { 
 if (hashTable[i] >= 300 && hashTable[i] < 399)  cout <<"\n |\t"<<i<<"\t|\t"<<hashTable[i]<<"\t|";  } 
 } 
 cout<<"\n -----------------------------"; 
 cout<<"\n Do you want to display any book details(y/n): ";  string yesno; 
 cin>>yesno; 
 if(yesno == "y") 
 { 
 k.SearchItem(); 
 } 
 else 
 { 
 cout<<"\n Thanks for Displaying Hash Table!!!\n";  } 
};
void Items::SaveHashTable() 
{ 
 fstream f1,f2; 
 int m; 
 f1.open("HashTable.txt", ios::out); 
 f2.open("Records.txt", ios::out); 
 for(int i = 0; i < TABLE_SIZE; i++) 
 { 
 m = hashTable[i]; 
 if(hashTable[i] != -1) 
 { 
 f1<<i<<" "<<m<<endl; 
 f2<<i<<" "<<hashTable[i]<<" "<<value[i][0]<<" "<<value[i][1]<<" "<<value[i][2]<<"  "<<value[i][3]<<endl; 
 } 
 } 
 f1.close(); 
 f2.close(); 
}; 
void Items::ReadHashTable() 
{ 
 ifstream f1,f2; 
 f1.open("HashTable.txt", ios::in); 
 f2.open("Records.txt", ios::in); 
 int j, m;
 int f,g; 
 while(f1 >>j>> m) 
 { 
 hashTable[j] = m; 
 } 
 f1.close(); 
 while(f2 >>f >> g>> bookId>> bookItem>> bookType>> bookPrice)  { 
 value[f][0] = bookId; 
 value[f][1] = bookItem; 
 value[f][2] = bookType; 
 value[f][3] = bookPrice; 
 } 
 f2.close(); 
}; 
int main() 
{ 
 cout<<"\n >>>>>> BOOK CENTER <<<<<<"; 
 cout<<"\n >>>>>> METHOD BASED ON DOUBLE HASHING <<<<<< \n";  Items i; 
 int choice; 
 hashTable = new int[TABLE_SIZE]; 
 curr_size = 0;
 for (int i=0; i<TABLE_SIZE; i++) 
 { 
 hashTable[i] = -1; 
 } 
 i.ReadHashTable(); 
 while(1) 
 { 
 system("COLOR 5F");
 cout<<"\n :::::::::: MENU ::::::::::";  cout<<"\n 1. Add Books"; 
 cout<<"\n 2. Delete Books "; 
 cout<<"\n 3. Search and Modify Books";  cout<<"\n 4. Display Books"; 
 cout<<"\n 5. Exit"; 
 cout<<"\n :::::::::::::::::::::::::::";  cout<<"\n\n Enter your choice: ";  cin>>choice; 
 switch(choice) 
 { 
 case 1 :system("COLOR 9E");i.AddItems(); 
 break; 
 case 2 : system("COLOR 4E");i.DeleteItems(); 
 break;
 case 3 : system("COLOR 6E");i.SearchItem(); 
 break; 
 case 4 : system("COLOR 9F");i.DisplayItem(); 
 break; 
 case 5 : system("COLOR 4E");exit(0); 
 break; 
 default: printf("\n Please enter valid input.\n "); 
 } 
}
}
