#include"escena.h"
#include<QApplication>

int main(int argc,char*argv[]){

 QApplication a(argc,argv);
 Escena E;
 E.setFixedSize(500,500);
 E.show();

 return a.exec();
}

