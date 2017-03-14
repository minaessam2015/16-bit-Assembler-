#include <iostream>
#include<fstream>
#include<string>
#include<vector>

#include<cstdlib>
using namespace std;
class symbolTable {
    private:
 string name;
unsigned int value;
    public:
     symbolTable(string n,int v){
     name=n;
     value=v;
     }
     symbolTable(string n){
     name=n;
     }
     void addValue(int v){
     value=v;
     }

   string getName(){
    return name;
   }
     int getValue(){
     return value;
     }
   void print(symbolTable table){
     cout<<table.name<<"  "<<table.value;
     }

};

    int checkName(string n,vector<symbolTable> table){
     for(unsigned int i=0;i<table.size();i++){

        if(table[i].getName()==n) {return (table[i].getValue());}
     }
     return -1;
     }

 /*  unsigned  int getValue(string s,vector<symbolTable> table){
     for(unsigned int i=0;i<table.size();i++)
     {
         if(s==table[i].getName()) return table[i].getValue();
     }
     }*/
 /* void pritnall(vector<symbolTable> table){
  for(unsigned int i=0;i<table.size();i++){
    cout<<table[i].getName()<<"  "<<table[i].getValue()<<"\n";
  }
  }*/

   string toBinary(int val)

{  // cout<<val<<"\n";
    string s;
   unsigned int mask = 1 << (sizeof(int) * 8 - 1);

   for(unsigned int i = 0; i < sizeof(int) * 8; i++)
   {
      if( (val & mask) == 0 )

        {

          s+='0' ;
        }

      else
        {

           s+='1' ;
        }

      mask  >>= 1;

   }
   s.erase(s.begin(),s.begin()+17);
   //cout<<s<<"\n";
  return s;
}

  int getNumber(string s){
      int i=0;
  while(isdigit(s[i])){
    i++;
  }
  if(i==s.size()){
    return atoi(s.c_str());
  }
  else return -1;

  }

  string jumping(string s)
  {
          if(s.empty()) return "000";

     else if(s=="JGT") return "001";
     else if(s=="JEQ") return "010";
     else if(s=="JGE") return "011";
     else if(s=="JLT") return "100";
     else if(s=="JNE") return "101";
     else if(s=="JLE") return "110";
     else return "111";

  }
 string destination(string s)
 {
          if(s.empty()) return "000";
     else if(s=="M")   return "001";
     else if(s=="D")   return "010";
     else if(s=="MD")  return "011";
     else if(s=="A")   return "100";
     else if(s=="AM")  return "101";
     else if(s=="AD")  return "110";
     else return "111";
 }

  string compt(string s){
  // a=0
       if(s=="0")   return "0101010";
  else if(s=="1")   return "0111111";
  else if(s=="-1")  return "0111010";
  else if(s=="D")   return "0001100";
  else if(s=="A")   return "0110000";
  else if(s=="!D")  return "0001101";
  else if(s=="!A")  return "0110001";
  else if(s=="-D")  return "0001111";
  else if(s=="-A")  return "0110011";
  else if(s=="D+1") return "0011111";
  else if(s=="A+1") return "0110111";
  else if(s=="D-1") return "0001110";
  else if(s=="A-1") return "0110010";
  else if(s=="D+A") return "0000010";
  else if(s=="D-A") return "0010011";
  else if(s=="A-D") return "0000111";
  else if(s=="D&A") return "0000000";
  else if(s=="D|A") return "0010101";
  // a=1
  else if(s=="M")   return "1110000";
  else if(s=="!M")  return "1110001";
  else if(s=="-M")  return "1110011";
  else if(s=="M+1") return "1110111";
  else if(s=="M-1") return "1110010";
  else if(s=="D+M") return "1000010";
  else if(s=="D-M") return "1010011";
  else if(s=="M-D") return "1000111";
  else if(s=="D&M") return "1000000";
  else              return "1010101";

   }

string removeSpaces(string line){
    string newline;
for (int i=0;i<line.size();i++){
    if(line[i]!=' ') newline+=line[i];
 }
  return newline;
}
int main()

{
    // initializing table to the predefined values

       vector<symbolTable> table;
table.push_back(symbolTable("R0",0));
table.push_back(symbolTable("R1",1));
table.push_back(symbolTable("R2",2));
table.push_back(symbolTable("R3",3));
table.push_back(symbolTable("R4",4));
table.push_back(symbolTable("R5",5));
table.push_back(symbolTable("R6",6));
table.push_back(symbolTable("R7",7));
table.push_back(symbolTable("R8",8));
table.push_back(symbolTable("R9",9));
table.push_back(symbolTable("R10",10));
table.push_back(symbolTable("R11",11));
table.push_back(symbolTable("R12",12));
table.push_back(symbolTable("R13",13));
table.push_back(symbolTable("R14",14));
table.push_back(symbolTable("R15",15));
table.push_back(symbolTable("SCREEN",16384));
table.push_back(symbolTable("KBD",24576));
table.push_back(symbolTable("SP",0));
table.push_back(symbolTable("LCL",1));
table.push_back(symbolTable("ARG",2));
table.push_back(symbolTable("THIS",3));
table.push_back(symbolTable("THAT",4));


   ofstream testFile;  // modified assembly
   testFile.open("testingOutput");

    int linesNum=0;
    int regNum=16;
    string line;
    string l;
    ifstream demo;   // untouched assembly
   demo.open("Pong.asm");
   if(demo.is_open()){

 whil:
    while(getline(demo,line)){


      if(line.empty()){ goto whil; }

    std::size_t comments = line.find("//");

  if (comments!=std::string::npos)
  {
        line.erase(comments,line.size());
           if(line.empty()){goto whil; }
  }
   string l;
     std::size_t lable = line.find("(");

  if (lable!=std::string::npos)    // extracting labels
  {
   l.insert(0,line,lable+1,line.size()-2);

   if(checkName(l,table)==-1){

    table.push_back(symbolTable(l,linesNum));

   }

   goto whil;

  }


       testFile<<line<<"\n";
 //cout<<linesNum<<"  "<<line<<"\n";
  linesNum++;

    }

   }
   else cout<<"error opening untouched assembly\n";
  testFile.close();
demo.close();
demo.open("testingOutput");
testFile.open("Pong.hack");

if(demo.is_open()){
 repeat:                        // get the new line
while(getline(demo,line)){


  // A-instruction
  std::size_t lable = line.find("@");
  int value;
  if (lable!=std::string::npos)
  {
  l="";
   l.insert(0,line,lable+1,line.size()-1);

   value=getNumber(l);

   if(value!=-1){                // @number

    l=toBinary(value);

    testFile<<"0"<<l<<"\n";
   }
   else{                                     // @variable
          value=checkName(l,table);
        //  cout<<value<<":\n";
    if(value==-1){                               // new variable
        table.push_back(symbolTable(l,regNum));
     l=toBinary(regNum);

   testFile<<"0"<<l<<"\n";
        regNum++;
    }
    else{

                // old variable
   l=toBinary(value);

   testFile<<"0"<<l<<"\n";
    }
   }

   goto repeat;
  }

  // C-instruction
  else{
        string jump,dest,comp;
        bool isJump=0;
     std::size_t j = line.find(";");

  if (j!=std::string::npos)    // extracting jumps
  {
   jump.insert(0,line,j+1,3);
   isJump=1;
   }

     std::size_t equals = line.find("=");

  if (equals!=std::string::npos)    // destination and computation
  {
   dest.insert(0,line,0,equals);
   if(isJump){
    comp.insert(0,line,equals+1,j-equals);

   }
  else{
    comp.insert(0,line,equals+1,line.size()-equals);

  }
   }
   else
   {
       comp.insert(0,line,0,j);
       dest="";
   }

   comp=removeSpaces(comp);
   dest=removeSpaces(dest);
   jump=removeSpaces(jump);
   testFile <<"111"<<compt(comp)<<destination(dest)<<jumping(jump)<<"\n";

  }

}
}
 //pritnall(table);

}




