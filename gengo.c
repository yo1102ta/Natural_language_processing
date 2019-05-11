#include <stdio.h>
#include <ctype.h>

/*構造体の宣言*/
typedef struct asc2{
  char mozi;
  int fre;
  int tenfig;
  int id;
} ASC2;
c
/*重複した頻度をid順にソート*/
void sort3(ASC2 a[]) {
  /*ループカウンタ*/
  int i,j;
  /*避難所*/
  ASC2 dumy;
  /*配列を回す*/
  for(i = 0; i < 93; i++){
    for(j = i + 1; j < 93; j++){
      /*文字が頻度が一致していてかつ10進数番号が同じなら入れ替え*/
      if(a[i].fre==a[j].fre){
	if(a[i].tenfig==a[j].tenfig){
	  /*id順で場所の入れ替え*/
	  if(a[i].id>a[j].id){
	    /*スワップ*/
	    dumy=a[i];
	    a[i].id = a[j].id;
	    a[j]=dumy;
	  }
	}	
      }
    }
  }
}
/*頻度が同じときの並びの処理*/
void sort2(ASC2 a[], int i, int j) {
  /*避難*/
  ASC2 tmp;
  /*id順でスワップ*/
  if(a[i].id>a[j].id){
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
  }
}
/*sortした後に再ソートして順番を直す*/
void sort4(ASC2 a[]){
  /*ループカウンタ*/
  int i,j;
  /*避難所*/
  ASC2 dumy;
  /*配列を回す*/
  for(i = 0; i < 93; i++){
    for(j = i + 1; j < 93; j++){
      /*頻度を比較*/
      if(a[i].fre <a[j].fre){
	/*頻度が高い順にスワップ*/
	dumy = a[i];
	a[i] = a[j];
	a[j] = dumy;
      }
    }
    /*頻度が同じなら、idで順番を決める*/
    if(a[i].fre==a[j].fre){
      sort2(a,i,j);
    }
  }
}
/*ソート*/
void sort(ASC2 a[]) {
  /*ループカウンタ*/
  int i,j;
  /*避難*/
  ASC2 dumy;
  /*配列を回す*/
  for(i = 0; i < 93; i++){
    for(j = i + 1; j < 93; j++){
      /*頻度の大小比較*/
      if(a[i].fre <a[j].fre){
	/*頻度の高い順にスワップ*/
	dumy = a[i];
	a[i] = a[j];
	a[j] = dumy;
      }/*頻度が一緒ならidで比較*/
      if(a[i].fre==a[j].fre){
	sort2(a,i,j);
      }
      /*10進数が一緒なら同じ文字なので頻度を共有*/
      if(a[i].tenfig==a[j].tenfig){
	a[i].fre+=a[j].fre;
	a[j].fre=a[i].fre;
      }
      
    }
  }
  
}
void sort5(ASC2 a[]){
  /*ループカウンタ*/
  int j,c=0;
  /*避難*/
  ASC2 dumy;
  /*配列を回す*/
  for(j = 0; j < 93; j++){
    /*10進数で同一のアルファベットを比較*/
    if(a[j].tenfig==a[j+1].tenfig){
      /*id56以降の文字と交換のためにcで移動*/
      while(a[j+c].id <= 56){
	c++;
      }
      dumy=a[j+c];
      a[j+c+30]=a[j+1];
      a[j+1]=dumy;
      c=0;
    }
  }
}
int main(void) {
  /*構造体の宣言*/
  ASC2 array[93] =
    {
      {'!',0,33,0},
      {'\"',0,34,1},
      {'#',0,35,2},
      {'$',0,36,3},
      {'%',0,37,4},
      {'\'',0,38,5},
      {'(',0,40,6},
      {')',0,41,7},
      {'*',0,42,8},
      {'+',0,43,9},
      {',',0,44,10},
      {'-',0,45,11},
      {'.',0,46,12},
      {'/',0,47,13},
      {'0',0,48,14},
      {'1',0,49,15},
      {'2',0,50,16},
      {'3',0,51,17},
      {'4',0,52,18},
      {'5',0,53,19},
      {'6',0,54,20},
      {'7',0,55,21},
      {'8',0,56,22},
      {'9',0,57,23},
      {':',0,58,24},
      {';',0,59,25},
      {'<',0,60,26},
      {'=',0,61,27},
      {'>',0,62,28},
      {'?',0,63,29},
      {'@',0,64,30},
      {'A',0,65,31},
      {'B',0,66,32},
      {'C',0,67,33},
      {'D',0,68,34},
      {'E',0,69,35},
      {'F',0,70,36},
      {'G',0,71,37},
      {'H',0,72,38},
      {'I',0,73,39},
      {'J',0,74,40},
      {'K',0,75,41},
      {'L',0,76,42},
      {'M',0,77,43},
      {'N',0,78,44},
      {'O',0,79,45},
      {'P',0,80,46},
      {'Q',0,81,47},
      {'R',0,82,48},
      {'S',0,83,49},
      {'T',0,84,50},
      {'U',0,85,51},
      {'V',0,86,52},
      {'W',0,87,53},
      {'X',0,88,54},
      {'Y',0,89,55},
      {'Z',0,90,56},
      {'[',0,91,57},
      {'\\',0,92,58},
      {']',0,93,59},
      {'^',0,94,60},
      {'_',0,95,61},
      {'`',0,96,62},
      {'a',0,65,63},
      {'b',0,66,64},
      {'c',0,67,65},
      {'d',0,68,66},
      {'e',0,69,67},
      {'f',0,70,68},
      {'g',0,71,69},
      {'h',0,72,70},
      {'i',0,73,71},
      {'j',0,74,72},
      {'k',0,75,73},
      {'l',0,76,74},
      {'m',0,77,75},
      {'n',0,78,76},
      {'o',0,79,77},
      {'p',0,80,78},
      {'q',0,81,79},
      {'r',0,82,80},
      {'s',0,83,81},
      {'t',0,84,82},
      {'u',0,85,83},
      {'v',0,86,84},
      {'w',0,87,85},
      {'x',0,88,86},
      {'y',0,89,87},
      {'z',0,90,88},
      {'{',0,123,89},
      {'|',0,124,90},
      {'}',0,125,91},
      {'~',0,126,92},	
    };
  /*ループカウンタ*/
  int i=0;
  /*入力文字受け取り*/
  char x;

  
  
  /*ファイルの最後まで呼び出し*/
  while ((x=getchar()) != EOF) {
    /*登録した文字とxを比較*/
    for(i=0;i<93;i++){
      /*一致したら頻度+1*/
      if(x==array[i].mozi){
	array[i].fre +=1; 
      }
    }
  }
  /*ソート処理*/
      sort(array);
/*重複した頻度をid順にソート*/
      sort3(array);
      /*sort3で乱れた順番を再ソート*/
      sort4(array);
      /*頻度0以外出力*/
      sort5(array);
  for (i = 0; i < 93; i++) {
    if (array[i].fre != 0) {
      printf("%c %3d\n", array[i].mozi, array[i].fre);
    }
  }
  
  return 0;
}