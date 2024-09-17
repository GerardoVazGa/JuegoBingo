#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip> 
#include <ctime>
#include <conio.h>
#include <fstream>
#include <unistd.h>
#include <ctype.h>
#include <windows.h>
#include <stdio.h>

enum colores {negro=0, azul, verde, cyan, rojo, magenta, marron, grisclaro, grisoscuro, azulclaro, verdeclaro, cyanclaro, rojoclaro, magentaclaro, amarillo, blanco};

using namespace std;

int opc, opc1, come=4, valal=0,posal=23;
char *alias1, *alias2;

void llenarTablerody(int **tablero, int ren, int col);
bool revisarSiGanaY(int **tablero, int ren, int col);
int modoCartaY();
bool revisarTableroY(int numero,int **tablero,int ren,int col,int *v,int  &indice,int &acum);
void mostrarY(int** tablero1, int** tablero2, int ren, int col, int numero, int contador,int x,int acum1,int acum2, int indice1,int indice2,int*vector1,int*vector2, int cont);
int LineaHorizontal(int *puntos);
bool revisartableroh(int numero,int **m,int ren,int col,int *v,int  &indice,int &acum);
void mostrarh(int**, int**, int ren ,int col, int,int,int,int,int,int,int,int*,int*,int);
bool revisarsiganah(int **m,int ren, int col);
int CartaCompleta(int *puntos);
void mostrarc(int,int**, int**, int ren, int col, int,int,int,int,int,int,int,int*,int*,int);
bool revisarsiganac(int **m,int ren, int col);
bool revisartableroc(int numero,int **m,int ren,int col,int *v,int  &indice,int &acum);
void llenartablero(int **mat,int ren, int col);
void shuffle(int *array,int n);
void menu();
void subMenu();
char *alias(string texto);

int modoDiagonal();
bool revisartablerod(int numero,int **m,int ren,int col,int *v,int  &indice,int &acum);
bool revisarsiganad(int **m,int ren, int col);

int grabarDatos(char *,string,int);
int leerDatos(int);
int maximoGanador(string *maximo,int);
int contarLineas();
int leerArch();

int **pedirespacio(int ren, int col);
void Color(int Background, int Text);
void gotoxy(int x, int y);
void textcolor(int n);

int main(){
	int puntos=0,ok=0;
	gotoxy(10,10);system("PAUSE");
	getchar();
	ok=leerArch();
	ok=0;
	do{
		menu();
		gotoxy(26,17);
		cin>>opc;
		switch(opc){
			case 1:alias1=alias("Ingresa el alias del primer jugador: ");
				   posal+=3;
				   alias2=alias("Ingresa el alias del segundo jugador: ");
				   posal-=3;
				   break;
				case 2: if(valal>=2){
							LineaHorizontal(&puntos);
							Beep(350,300);Beep(700,150);Beep(350,300);Beep(700,150);
							break;
						}
						else{
							break;
						}
				case 3:if(valal>=2){
							CartaCompleta(&puntos);
							Beep(350,300);Beep(700,150);Beep(350,300);Beep(700,150);
							break;
						}
						else{
							break;
						}
				case 4:	//llamar diagonal completa
						if(valal>=2){
							modoDiagonal();
							Beep(350,300);Beep(700,150);Beep(350,300);Beep(700,150);
							break;
						}
						else{
							break;
						}
				case 5:	if(valal>=2){
							modoCartaY();
							Beep(350,300);Beep(700,150);Beep(350,300);Beep(700,150);
							break;
						}
						else{
							break;
						}
				case 6: if(valal>=2){
						do{
						subMenu();
						cin>>opc1;
						Beep(1500,300);Beep(700,150);Beep(1350,300);
						switch(opc1){
							case 1:ok = leerDatos(opc1);
									if (ok == 1){
										cout << "Error en el archivo..." << endl;
									}break;//llamar registradas
							case 2:
									ok = leerDatos(opc1);
									if (ok == 1){
										cout << "Error en el archivo..." << endl;
									}break;//llamar por jugador
							case 3:
									ok = leerDatos(opc1);
									if (ok == 1){
										cout << "Error en el archivo..." << endl;
									}break;//llamar modo hor
							case 4:
									ok = leerDatos(opc1);
									if (ok == 1){
										cout << "Error en el archivo..." << endl;
									}break;//llamar carta completa
							case 5:
									ok = leerDatos(opc1);
									if (ok == 1){
										cout << "Error en el archivo..." << endl;
									}break;//llamar diagonal stats
							case 6:
									ok = leerDatos(opc1);
									if (ok == 1){
										cout << "Error en el archivo..." << endl;
									}break;//llamar maximo
							case 7:
									ok = leerDatos(opc1);
									if (ok == 1){
										cout << "Error en el archivo..." << endl;
									}break;//nada
						}
						
						}while(opc1!=8);
						}
						else{
							break;
						}
				case 7: break;
			default: cout<<"xddd";break; 
				}
		}while(opc!=7);
	return 0;
}

int leerArch(){
	system("cls");
	system("color 0B");
	textcolor(cyanclaro);
	fstream arch;
	char linea[110];
	arch.open("BINGO.txt",ios::in);
	if(!arch){
		cout<<"No se pudo abrir el archivo"<<endl;
		return 1;
	}
	time_t tiemp;
	char fecha[15];
	char hora[12];
	struct tm *tiempFech;
	
	tiemp=time(NULL);
	tiempFech=localtime(&tiemp);
	strftime(fecha, 15, "%d/%b/%Y", tiempFech);
	strftime(hora, 12, "%I:%M%p", tiempFech);
	gotoxy(5,50);cout<<fecha<<" "<<hora;
	int i=3;
	arch.getline(linea,110,'\n');
	while(!arch.eof()){
		gotoxy(20,i++);cout<<linea;Beep(i*300,500);
		arch.getline(linea,110,'\n');
	}
	gotoxy(50,25);cout<<"Proyecto Programacion I";
	textcolor(rojo);
	gotoxy(10,30);cout<<"Maestra: Georgina Salazar Partida";Sleep(1500);Beep(400,1500);
	textcolor(rojoclaro);
	gotoxy(10,35);cout<<"Proyecto realizado por: ";Sleep(1000);
	textcolor(rojo);
	gotoxy(50,37);cout<<"Isidro Hernández Guel";Beep(1200,250);Sleep(500);
	gotoxy(50,39);cout<<"Gerardo Vázquez Galindo";Beep(450,250);Sleep(500);
	gotoxy(50,41);cout<<"Jaime Adolfo Varela Martínez";Beep(800,750);Sleep(500);

	arch.close();
	do{
		gotoxy(50,50);cout<<"PRESS ENTER";Sleep(500);
		gotoxy(50,50);cout<<"           ";Sleep(500);
	}while(!getchar());
	Beep(500,100);Beep(430,150);Beep(950,1000);
	return 0;

}

void menu(){
	system("cls");
	system("color F4");
	cout<<endl<<"Bingo";
	if(valal<2){
		Color(blanco, negro);gotoxy(20,8);cout<<"1. Ingresar alias de lo jugadores";
	}
	else{
		Color(blanco, negro);gotoxy(20,8);cout<<"1. Cambiar alias de lo jugadores";
	}
	Color(blanco, come);
	gotoxy(20,9);cout<<"2. Modo linea horizontal";
	gotoxy(20,10);cout<<"3. Modo toda la carta";
	gotoxy(20,11);cout<<"4. Modo diagonal principal";
	gotoxy(20,12);cout<<"5. Modo carta en Y";
	gotoxy(20,13);cout<<"6. Estadisticas";
	gotoxy(20,14);cout<<"7. Salir";
	Color(blanco,negro);
	gotoxy(20,16);cout<<"Opcion:";
	gotoxy(26,16);printf("\304\277");
	gotoxy(27,17);printf("\263");
	gotoxy(27,18);printf("\331");
	gotoxy(26,18);printf("\304");
	gotoxy(25,18);printf("\300");
	gotoxy(25,17);printf("\263");
}

void subMenu(){
	
	gotoxy(20,13);cout<<"6. Estadisticas";printf("\304\304\304\304\304");
	gotoxy(45,13);printf("\264");cout<<"1. Estadisticas registradas";
	gotoxy(45,14);printf("\263");cout<<"2. Estaditisticas por jugador";
	gotoxy(45,15);printf("\263");cout<<"3. Estadisticas por modo horizontal";
	gotoxy(45,16);printf("\263");cout<<"4. Estadisticas por modo de carta completo";
	gotoxy(45,17);printf("\263");cout<<"5. Estadisticas por modo una diagonal principal";
	gotoxy(45,18);printf("\263");cout<<"6. Estadisticas por modo de carta en Y";
	gotoxy(45,19);printf("\263");cout<<"7. Maximo ganador por modo";
	gotoxy(45,20);printf("\263");cout<<"8. Regresar";
	gotoxy(45,22);cout<<"Opcion:";
	gotoxy(46,22);printf("\304\277");
	gotoxy(47,23);printf("\263");
	gotoxy(47,24);printf("\331");
	gotoxy(46,24);printf("\304");
	gotoxy(44,24);printf("\300");
	gotoxy(44,23);printf("\263");
}

int grabarDatos(char *alias,string modo,int puntos){
	fstream arch;
	
	arch.open("EstadisticasRegistradas.txt",ios::out|ios::app);
	if (!arch){
		cerr << "No se logro abrir el archivo..." << endl;
		
		return 1;
	}

  	time_t tiemp;
	char fecha[15];
	char hora[12];
	struct tm *tiempFech;
	
	tiemp=time(NULL);
	tiempFech=localtime(&tiemp);
	strftime(fecha, 15, "%d/%b/%Y", tiempFech);
	strftime(hora, 12, "%I:%M%p", tiempFech);
	gotoxy(10,30);cout << "Datos Almacenados!!!" << endl;

	arch << alias << " " << modo << " " << puntos << " " << fecha << " " << hora << endl;
		
	arch.close();
	system("PAUSE");
}

int leerDatos(int opc){
	fstream arch;
	system("cls");
	/*char fecha [10];
	char hora [8];*/
	string alias,unknown;
	string *maximo;
	int REG=contarLineas();
	maximo = new string[REG];
	string fecha,hora;
	int check=0;
	int indice = 0;
	int mayor=0,menor=0;
	arch.open("EstadisticasRegistradas.txt",ios::in);
	if (!arch){
		return 1;
	}
	string modo;
	int puntos;
	switch(opc){
	
		case 1:
		arch.seekg(0);
		arch >> alias >> modo >> puntos >> fecha >> hora;
		while(!arch.eof()){
			cout<<"Nombre: "<<alias;
			cout<<"\tModo: "<<modo;
			cout<<"\tPuntos: "<<puntos;
			cout<<"\tFecha: "<<fecha;
			cout<<"\tHora: "<<hora<<endl;
			arch >> alias >> modo >> puntos >> fecha >> hora;
		}break;
		case 2:
			cout<<"Que jugador quieres buscar?"<<endl;
			cin>>unknown;
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(alias==unknown){
					cout<<"Nombre: "<<alias;
					cout<<"\tModo: "<<modo;
					cout<<"\tPuntos: "<<puntos;
					cout<<"\tFecha: "<<fecha;
					cout<<"\tHora: "<<hora<<endl;
					check++;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			if(check==0)
				cout<<"Jugador no Registrado!!!"<<endl;
			break;
		case 3:
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="Horizontal"){
					cout<<"Nombre: "<<alias;
					cout<<"\tModo: "<<modo;
					cout<<"\tPuntos: "<<puntos;
					cout<<"\tFecha: "<<fecha;
					cout<<"\tHora: "<<hora<<endl;
					check++;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			if(check==0)
				cout<<"Nadie ha ganado en modo Horizontal!!!"<<endl;
			break;
		case 4:
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="Completa"){
					cout<<"Nombre: "<<alias;
					cout<<"\tModo: "<<modo;
					cout<<"\tPuntos: "<<puntos;
					cout<<"\tFecha: "<<fecha;
					cout<<"\tHora: "<<hora<<endl;
					check++;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			if(check==0)
				cout<<"Nadie ha ganado en modo Carta Completa!!!"<<endl;
			break;
		case 5:
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="Diagonal"){
					cout<<"Nombre: "<<alias;
					cout<<"\tModo: "<<modo;
	
				cout<<"\tPuntos: "<<puntos;
					cout<<"\tFecha: "<<fecha;
					cout<<"\tHora: "<<hora<<endl;
					check++;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			if(check==0)
				cout<<"Nadie ha ganado en modo Diagonal Principal!!!"<<endl;
			break;
		case 6:
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="ModoY"){
					cout<<"Nombre: "<<alias;
					cout<<"\tModo: "<<modo;
					cout<<"\tPuntos: "<<puntos;
					cout<<"\tFecha: "<<fecha;
					cout<<"\tHora: "<<hora<<endl;
					check++;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			if(check==0)
				cout<<"Nadie ha ganado en modo Y!!!"<<endl;
			break;
		case 7:
			int k=0;
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="Horizontal"){
					maximo[k++]=alias;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			indice=maximoGanador(maximo,k);
			cout<<"En modo Horizontal el maximo ganador es: "<<endl<<maximo[indice]<<endl;

			arch.close();

			arch.open("EstadisticasRegistradas.txt",ios::in);
			if (!arch){
				return 1;
			}

			indice = 0;
			k=0;
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="Completa"){
					maximo[k++]=alias;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			indice=maximoGanador(maximo,k);
			cout<<"En modo Completa el maximo ganador es: "<<endl<<maximo[indice]<<endl;

			arch.close();

			arch.open("EstadisticasRegistradas.txt",ios::in);
			if (!arch){
				return 1;
			}

			indice = 0;
			k=0;
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="Diagonal"){
					maximo[k++]=alias;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			indice=maximoGanador(maximo,k);
			cout<<"En modo Diagonal el maximo ganador es: "<<endl<<maximo[indice]<<endl;

			arch.close();

			arch.open("EstadisticasRegistradas.txt",ios::in);
			if (!arch){
				return 1;
			}

			indice = 0;
			k=0;
			arch.seekg(0);
			arch >> alias >> modo >> puntos >> fecha >> hora;
			while(!arch.eof()){
				if(modo=="ModoY"){
					maximo[k++]=alias;
				}
				arch >> alias >> modo >> puntos >> fecha >> hora;
			}
			indice=maximoGanador(maximo,k);
			cout<<"En modo Y el maximo ganador es: "<<endl<<maximo[indice]<<endl;

			break;
			


	}
	
	arch.close();
}

int maximoGanador(string *maximo,int k){
	int mayor = 0,menor = 0,indice = 0;
	for(int i=0;i<k;i++){
		for(int j=k-1;j>=i;j--){
			if(maximo[i]==maximo[j]){
				mayor++;
				if(mayor>menor)
					indice=i;
			}
			menor=mayor;
		}
		mayor=0;
	}
	return indice;
}

int contarLineas(){
	fstream arch("EstadisticasRegistradas.txt",ios::in);
	int totLin=0;
	char linea[80];
	arch.getline(linea,80,'\n');
	while(!arch.eof()){
		totLin++;
		arch.getline(linea,80,'\n');
	}
	arch.close();
	return totLin;
}

char *alias(string texto){
	int i;
	char *alias=new char[15];
	bool band=false;
	do{
		gotoxy(20,posal);cout<<texto<<"                                           ";
		gotoxy(20,posal+1);cout<<"                                              ";
		gotoxy(20,posal-1);cout<<"                                              ";
		gotoxy(57,posal);
		cin>>alias;
		if(strlen(alias)>=4 && strlen(alias)<=12){
			if(isalpha(alias[0])!= 0){
				for( i=1; i<strlen(alias); i++){
					if(isalpha(alias[i]) != 0 || isdigit(alias[i]) != 0 || alias[i]=='_'){
						
					}
					else{
						gotoxy(20,posal);cout<<"Error, el caracter '"<<alias[i]<<"' no esta permitido        ";
						gotoxy(20,posal+1);system("pause");
						break;
					}
				}
				if(i==strlen(alias)){
					band=true;
					gotoxy(20,posal+1);cout<<"Alias valido";
					gotoxy(20,posal+2);system("pause");
					come=0;
					valal++;
				}
			}
			else{
				gotoxy(20,posal);cout<<"Tu primer caracter no es una letra                     ";
				gotoxy(20,posal+1);system("pause");
			}
		}
		else{
			gotoxy(20,posal);cout<<"La longitud del alias no es valido                ";
			gotoxy(20,posal+1);system("pause");
		}
		if(band==false){
			Beep(1500,100);Beep(1200,150);Beep(750,200);Beep(1300,300);
		}
	}while(band==false);
	Beep(350,300);Beep(700,150);
	return alias;
}

int modoCartaY(){
	system("cls");
	system("color F4");
	int entradas=5;
	int ok=0;
	bool tabla1=false, tabla2=false;
	int **tablero1, **tablero2;
	tablero1=pedirespacio(entradas, entradas);
	tablero2=pedirespacio(entradas, entradas);
	int x=0, cont=0, c=1;
	int acum1=0, acum2=0;
	
	int *bolsa=new int[99];
	int numerosOk1[25], numerosOk2[25], indice1=0, indice2=0;
	
	llenarTablerody(tablero1, entradas, entradas);
	llenarTablerody(tablero2, entradas, entradas);
	
	for(int i=0; i<99; i++){
		bolsa[i]=i+1;
	}
	shuffle(bolsa, 99);
	
	for(int i=0; i<99; i++){
		tabla1=revisarTableroY(bolsa[i], tablero1, entradas, entradas, numerosOk1, indice1, acum1);
		tabla2=revisarTableroY(bolsa[i], tablero2, entradas, entradas, numerosOk2, indice2, acum2);
		
		mostrarY(tablero1, tablero2,entradas,entradas, bolsa[i], c++,x,acum1,acum2,indice1,indice2,numerosOk1,numerosOk2,cont);
		if(tabla1==true){
			x=1;
			break;
		}
		if(tabla2==true){
			x=2;
			break;
		}	
		
	}
	mostrarY(tablero1, tablero2,entradas,entradas, bolsa[c-1],c,x,acum1,acum2,indice1,indice2,numerosOk1,numerosOk2,cont);
	Beep(1500,100);Beep(1200,150);Beep(750,200);Beep(1300,100);Beep(1000,1000);Beep(600,150);Beep(750,100);Beep(1300,300);
	Color(blanco,negro);
	gotoxy(0,29);cout<<endl;
	if(x==1)
		ok = grabarDatos(alias1,"ModoY",acum1);
	else if(x==2)
		ok = grabarDatos(alias2,"ModoY",acum2);
	if (ok == 1){
		cout << "Error en el archivo..." << endl;
	}
	Sleep(1500);
	
}

bool revisarTableroY(int numero,int **tablero,int ren,int col,int *v,int  &indice,int &acum){
    bool exito=false;
    bool bandera;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
            if(tablero[i][j]==numero){
                v[indice++]=numero;
                acum+=numero;
                tablero[i][j]=0;
                exito=revisarSiGanaY(tablero,ren,col);
                if(exito==true){
                    return true;
                }
            }
    	}
	}
    return false;
}

bool revisarSiGanaY(int **tablero, int ren, int col){
	bool bandera=false;
	
	if(tablero[0][0]==0 && tablero[1][1]==0 && tablero[1][3]==0 && tablero[0][4]==0 && tablero[2][2]==0 && tablero[3][2]==0 && tablero[4][2]==0){
		return true;
	}
	
	return bandera;
}

void mostrarY(int** tablero1, int** tablero2, int ren, int col, int numero, int contador,int x,int acum1,int acum2, int indice1,int indice2,int*vector1,int*vector2, int cont){
	srand(time(NULL));
	int color, color1;
	int *numacum;
	int vector3[105];
	numacum=new int[100];
	
	color1=0+rand()%(14-1+1);
	Color(blanco, color1);
	gotoxy(52,2);printf("\332");Sleep(25);
	for(int i=53; i<69; i++){
		gotoxy(i,2);printf("\304");Sleep(25);
	}
	gotoxy(69,2);printf("\277");Sleep(25);
	gotoxy(69,3);printf("\263");Sleep(25);
	gotoxy(69,4);printf("\331");Sleep(25);
	for(int i=68; i>52; i--){
		gotoxy(i,4);printf("\304");Sleep(25);
	}
	gotoxy(52,4);printf("\300");Sleep(25);
	gotoxy(52,3);printf("\263");Sleep(25);
	
	color=0+rand()%(14-1+1);
	Color(blanco, color);
	gotoxy(53, 3); cout << "M"; Sleep(10);
	gotoxy(54, 3); cout << "o"; Sleep(10);
	gotoxy(55, 3); cout << "d"; Sleep(10);
	gotoxy(56, 3); cout << "o"; Sleep(10);
	gotoxy(57, 3); cout << " "; Sleep(10);
	gotoxy(58, 3); cout << " "; Sleep(10);
	gotoxy(59, 3); cout << "Y"; Sleep(10);
	

	Color(blanco, negro);
	
	gotoxy(10, 6); cout << "Numero generado: "<<numero; 
	Sleep(200);
	gotoxy(70, 6); cout << "Contador de numeros: "<<contador; 
	
	gotoxy(10,8);cout<<"Jugador 1: "<<alias1;
	gotoxy(10, 9); cout << "Aciertos: "<<indice1;
	gotoxy(10, 10); cout << "Lista de numeros: ";
	gotoxy(9, 11);
	for (int i = 0; i < indice1; i++)
	{
		cout <<setw(3) <<vector1[i]<<",";
			}
	gotoxy(70,8);cout<<"Jugador 2: "<<alias2;
	gotoxy(70, 9); cout << "Aciertos: "<<indice2;
	gotoxy(70, 10); cout << "Lista de numeros: ";
	gotoxy(69, 11);
	for (int i = 0; i < indice2; i++)
	{
		cout <<setw(3) <<vector2[i]<<",";
	}
	if(x == 1)
	{
		gotoxy(10,21);cout<<"Felicidades "<<alias1<<"!";
		gotoxy(70, 21); cout << "Acumulaste: "<<acum1<<" puntos";
	}
	else if(x == 2)
	{
		gotoxy(10,21);cout<<"Felicidades "<<alias2<<"!";
		gotoxy(62, 21); cout << "Acumulaste: "<<acum2<<" puntos";
	}
	
	gotoxy(0, 23); cout << "Todos los numeros que han salido: ";
	gotoxy(0, 24);
	vector3[cont++]=numero;
	for (int i = 0; i < cont; i++)
	{
		cout <<setw(3)<<vector3[i]<<",";
	}
	
	for (int i = 0; i < ren; i++)
	{
		for (int j = 0; j< col; j++)
		{
			if(tablero1[i][j]==0)
			{
				Color(amarillo, negro);
			}
			else
			{
				Color(blanco, negro);
			}
			gotoxy(10 + j * 5, 14 + i); printf(" %d ", tablero1[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < ren; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Sleep(25);
			if(tablero2[i][j]==0)
			{
				Color(amarillo, negro);
			}
			else
			{
				Color(blanco, negro);
			}
			gotoxy(70 + j * 5, 14 + i); printf(" %d ", tablero2[i][j]);
		}
		cout << endl;
	}
	Color(negro, blanco);
	
}

int modoDiagonal(){
	system("cls");
	system("color F4");
    srand(time(NULL));
    int nxn;
	nxn=rand()% 6 + 3;
    int ok=0;
    bool tabla1=false,tabla2=false;
    int **tablero1;
    int **tablero2;
    tablero1=pedirespacio(nxn,nxn);
    tablero2=pedirespacio(nxn,nxn);
    int c=1,x=0,cont=0;
    int acum1=0,acum2=0;
    int *bolsa=new int[99];
    int *numerosok1,*numerosok2,indice1=0,indice2=0;

    numerosok1=new int[nxn*nxn];
    numerosok2=new int[nxn*nxn];
    
   	llenarTablerody(tablero1,nxn,nxn);
    llenarTablerody(tablero2,nxn,nxn);

    for(int i=0;i<100;i++){
        bolsa[i]=i+1;
    }
    
    shuffle(bolsa,99);

    for(int i=0;i<99;i++){
       
        tabla1=revisartablerod(bolsa[i],tablero1,nxn,nxn,numerosok1,indice1,acum1);
        tabla2=revisartablerod(bolsa[i],tablero2,nxn,nxn,numerosok2,indice2,acum2);
        
        mostrarc(2,tablero1, tablero2,nxn,nxn, bolsa[i], c++,x,acum1,acum2,indice1,indice2,numerosok1,numerosok2,cont);
        if(tabla1==true){
			x=1;
			break;
		}
        
        if(tabla2==true){
           x=2;
           break;
		}
        cont++;
    }
    Beep(1500,100);Beep(1200,150);Beep(750,200);Beep(1300,100);Beep(1000,1000);Beep(600,150);Beep(750,100);Beep(1300,300);
    mostrarc(2,tablero1, tablero2,3,9, bolsa[c-1],c,x,acum1,acum2,indice1,indice2,numerosok1,numerosok2,cont);
	Color(blanco,negro);
	gotoxy(0,29);cout<<endl;
	if(x==1)
		ok = grabarDatos(alias1,"Diagonal",acum1);
	else if(x==2)
		ok = grabarDatos(alias2,"Diagonal",acum2);
	if (ok == 1){
		cout << "Error en el archivo..." << endl;
	}
	Sleep(1500);
}

bool revisartablerod(int numero,int **m,int ren,int col,int *v,int  &indice,int &acum){
    bool exito=false;
    bool bandera;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
            if(m[i][j]==numero){
                v[indice]=numero;
                indice++;
                acum=acum+numero;
                m[i][j]=0;
                exito=revisarsiganad(m,ren,col);
                if(exito==true){
                    return true;
                }
            }
    	}
	}
    return false;
}

bool revisarsiganad(int **m,int ren, int col){
    bool bandera=false;
    int cont=0;
    for(int i=0;i<ren;i++)
    	if(m[i][i]==0)
    		cont++;

    if(cont==col)
    	return true;
    cont=0;
    int j=col-1;
    int i=0;
    do{
    	if(m[i++][j--]==0)
    		cont++;
    }while(i<ren&&j>=0);
    if(cont==ren)
    	return true;
    	
    return bandera;
}

int CartaCompleta(int *puntos){
	system("cls");
	system("color F4");
    srand(time(0));
    int ok=0;
    bool tabla1=false,tabla2=false;
    int **tablero1;
    int **tablero2;
    int c=1,x=0,cont=0;
    int acum1=0,acum2=0;
    int *bolsa=new int[99];
    int numerosok1[28],numerosok2[28],indice1=0,indice2=0;
    
    tablero1=pedirespacio(3,9);
    tablero2=pedirespacio(3,9);
    
    llenartablero(tablero1,3,9);
    llenartablero(tablero2,3,9);


    for(int i=0;i<100;i++){
        bolsa[i]=i+1;
    }
    
    shuffle(bolsa,99);
    
    for(int i=0;i<99;i++){
       
        tabla1=revisartableroc(bolsa[i],tablero1,3,9,numerosok1,indice1,acum1);
        tabla2=revisartableroc(bolsa[i],tablero2,3,9,numerosok2,indice2,acum2);
        
        mostrarc(1,tablero1, tablero2,3,9, bolsa[i], c++,x,acum1,acum2,indice1,indice2,numerosok1,numerosok2,cont);
        if(tabla1==true){
			x=1;
			break;
		}
        
        if(tabla2==true){
           x=2;
           break;
		}
        cont++;
    }
    Beep(1500,100);Beep(1200,150);Beep(750,200);Beep(1300,100);Beep(1000,1000);Beep(600,150);Beep(750,100);Beep(1300,300);
    mostrarc(1,tablero1, tablero2,3,9, bolsa[c-1],c,x,acum1,acum2,indice1,indice2,numerosok1,numerosok2,cont);
	Color(blanco,negro);
	gotoxy(0,29);cout<<endl;
	if(x==1)
		ok = grabarDatos(alias1,"Completa",acum1);
	else if(x==2)
		ok = grabarDatos(alias2,"Completa",acum2);
	if (ok == 1){
		cout << "Error en el archivo..." << endl;
	}
	Sleep(1500);
	
}

bool revisartableroc(int numero,int **m,int ren,int col,int *v,int  &indice,int &acum){
    bool exito=false;
    bool bandera;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
            if(m[i][j]==numero){
                v[indice]=numero;
                indice++;
                acum=acum+numero;
                m[i][j]=0;
                exito=revisarsiganac(m,ren,col);
                if(exito==true){
                    return true;
                }
            }
    	}
	}
    return false;
}

bool revisarsiganac(int **m,int ren, int col){
    bool bandera=false;
    int cont=0;
    
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
            if(m[i][j]==0){
                cont++;
            	}
            }
        if(cont==(ren*col)){
            bandera=true;
            break;
        }
    }
    return bandera;
}

void mostrarTituloc(){
	srand(time(NULL));
	int color, color1;
	color=0+rand()%(14-1+1);
	Color(blanco, color);
	gotoxy(54, 3); cout << "M"; Sleep(10);
	gotoxy(55, 3); cout << "o"; Sleep(10);
	gotoxy(56, 3); cout << "d"; Sleep(10);
	gotoxy(57, 3); cout << "o"; Sleep(10);
	gotoxy(63, 3); cout << "C"; Sleep(10);
	gotoxy(64, 3); cout << "a"; Sleep(10);
	gotoxy(65, 3); cout << "r"; Sleep(10);
	gotoxy(66, 3); cout << "t"; Sleep(10);
	gotoxy(67, 3); cout << "a"; Sleep(10);
	gotoxy(57, 4); cout << "C"; Sleep(10);
	gotoxy(58, 4); cout << "o"; Sleep(10);
	gotoxy(59, 4); cout << "m"; Sleep(10);
	gotoxy(60, 4); cout << "p"; Sleep(10);
	gotoxy(61, 4); cout << "l"; Sleep(10);
	gotoxy(62, 4); cout << "e"; Sleep(10);
	gotoxy(63, 4); cout << "t"; Sleep(10);
	gotoxy(64, 4); cout << "a"; Sleep(10);
}

void mostrarTitulod(){
	srand(time(NULL));
	int color, color1;
	color=0+rand()%(14-1+1);
	Color(blanco, color);
	gotoxy(54, 3); cout << "M"; Sleep(10);
	gotoxy(55, 3); cout << "o"; Sleep(10);
	gotoxy(56, 3); cout << "d"; Sleep(10);
	gotoxy(57, 3); cout << "o"; Sleep(10);
	gotoxy(59, 3); cout << "D"; Sleep(10);
	gotoxy(60, 3); cout << "i"; Sleep(10);
	gotoxy(61, 3); cout << "a"; Sleep(10);
	gotoxy(62, 3); cout << "g"; Sleep(10);
	gotoxy(63, 3); cout << "o"; Sleep(10);
	gotoxy(64, 4); cout << "n"; Sleep(10);
	gotoxy(65, 4); cout << "a"; Sleep(10);
	gotoxy(66, 4); cout << "l"; Sleep(10);
}

void mostrarc(int mode,int** tablero1, int** tablero2, int ren, int col, int numero, int contador,int x,int acum1,int acum2, int indice1,int indice2,int*vector1,int*vector2, int cont){
	srand(time(NULL));
	int color, color1;
	int *numacum;
	int vector3[105];
	numacum=new int[100];
	
	color1=0+rand()%(14-1+1);
	Color(blanco, color1);
	gotoxy(52,2);printf("\332");Sleep(25);
	for(int i=53; i<69; i++){
		gotoxy(i,2);printf("\304");Sleep(25);
	}
	gotoxy(69,2);printf("\277");Sleep(25);
	gotoxy(69,3);printf("\263");Sleep(25);
	gotoxy(69,4);printf("\263");Sleep(25);
	gotoxy(69,5);printf("\331");Sleep(25);
	for(int i=68; i>52; i--){
		gotoxy(i,5);printf("\304");Sleep(25);
	}
	gotoxy(52,5);printf("\300");Sleep(25);
	gotoxy(52,4);printf("\263");Sleep(25);
	gotoxy(52,3);printf("\263");Sleep(25);
	
	if(mode==1)
		mostrarTituloc();
	else if(mode==2)
		mostrarTitulod();
	
	Color(blanco, negro);
	
	gotoxy(10, 6); cout << "Numero generado: "<<numero; 
	Sleep(200);
	gotoxy(70, 6); cout << "Contador de numeros: "<<contador; 
	
	gotoxy(10,8);cout<<"Jugador 1: "<<alias1;
	gotoxy(10, 9); cout << "Aciertos: "<<indice1;
	gotoxy(10, 10); cout << "Lista de numeros: ";
	gotoxy(10, 11);
	for (int i = 0; i < indice1; i++)
	{
		cout <<setw(2) <<vector1[i]<<",";
			}
	gotoxy(70,8);cout<<"Jugador 2: "<<alias2;
	gotoxy(70, 9); cout << "Aciertos: "<<indice2;
	gotoxy(70, 10); cout << "Lista de numeros: ";
	gotoxy(70, 11);
	for (int i = 0; i < indice2; i++)
	{
		cout <<setw(2) <<vector2[i]<<",";
			}
	if(x == 1)
	{
		gotoxy(10,21);cout<<"Felicidades "<<alias1<<"!";
		gotoxy(70, 21); cout << "Acumulaste: "<<acum1<<" puntos";
	}
	else if(x == 2)
	{
		gotoxy(10,21);cout<<"Felicidades "<<alias2<<"!";
		gotoxy(62, 21); cout << "Acumulaste: "<<acum2<<" puntos";
	}
	
	gotoxy(0, 23); cout << "Todos los numeros que han salido: ";
	gotoxy(0, 24);
	vector3[cont]=numero;
	for (int i = 0; i < cont+1; i++)
	{
		cout <<setw(3)<<vector3[i]<<",";
	}
	
	for (int i = 0; i < ren; i++)
	{
		for (int j = 0; j< col; j++)
		{
			if(tablero1[i][j]==0)
			{
				Color(amarillo, negro);
			}
			else
			{
				Color(blanco, negro);
			}
			gotoxy(10 + j * 5, 14 + i); printf(" %d ", tablero1[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < ren; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Sleep(25);
			if(tablero2[i][j]==0)
			{
				Color(amarillo, negro);
			}
			else
			{
				Color(blanco, negro);
			}
			gotoxy(70 + j * 5, 14 + i); printf(" %d ", tablero2[i][j]);
		}
		cout << endl;
	}
	Color(negro, blanco);
	
}

void shuffle(int *array,int n){
    if(n>1){
        int i;
        for(i=0;i<n-1;i++){
            int j=i+rand()/(RAND_MAX/(n-i)+1);
            int t=array[j];
            array[j]=array[i];
            array[i]=t;
        }
    }
}

int **pedirespacio(int ren, int col){
    int **aux;
    aux=new int *[ren];
    for(int i=0;i<ren;i++)
        aux[i]=new int[col];
    return aux;
}

void llenartablero(int **mat,int ren, int col){
    int *vec;
    vec=new int[99];
    
    for(int i=0;i<99;i++){
        vec[i]=i+1;
    }
    shuffle(vec,99);
    int *aux;
    aux=new int[9];
    int inicio=0;
    int fin=5;
    
    for(int r=0;r<ren;r++){
    for(int i=0;i<9;i++){
        aux[i]=0;
    }
        int cont=0;
        
    for(int i=inicio;i<fin;i++){
        aux[cont]=vec[i];
        cont++;
    }
    shuffle(aux,9);
        for(int c=0;c<col;c++){
            mat[r][c]=aux[c];
        }
        inicio=fin;
        fin+=5;
        
    }
    
}

void llenarTablerody(int **tablero, int ren, int col){
	int *vec;
	vec=new int [99];
	int inicio=0, final=col;
	for(int i=0; i<99; i++){
		vec[i]=i+1;
	}
	
	shuffle(vec, 99);
	
	int *aux;
	aux=new int[ren*col];
	
	
	for(int i=0; i<(ren*col); i++)
		aux[i]=vec[i];
	int k=0;
	for(int i=0; i<ren; i++)
		for(int j=0;j<col;j++)
			tablero[i][j]=aux[k++];
	
}

int LineaHorizontal(int *puntos){
	system("cls");
	system("color F4");
    srand(time(0));
    bool tabla1=false,tabla2=false;
    int **tablero1;
    int **tablero2;
    int c=1,x=0,cont=0;
    int acum1=0,acum2=0;
    int *bolsa=new int[99];
    int numerosok1[9],numerosok2[9],indice1=0,indice2=0;
    int ok=0;
    
    tablero1=pedirespacio(3,9);
    tablero2=pedirespacio(3,9);
    
    llenartablero(tablero1,3,9);
    llenartablero(tablero2,3,9);


    for(int i=0;i<100;i++){
        bolsa[i]=i+1;
    }
    
    shuffle(bolsa,99);
    
    for(int i=0;i<99;i++){
       
        tabla1=revisartableroh(bolsa[i],tablero1,3,9,numerosok1,indice1,acum1);
        tabla2=revisartableroh(bolsa[i],tablero2,3,9,numerosok2,indice2,acum2);
        
        mostrarh(tablero1, tablero2,3,9, bolsa[i], c++,x,acum1,acum2,indice1,indice2,numerosok1,numerosok2,cont);
        if(tabla1==true){
			x=1;
			
			break;
		}
        
        if(tabla2==true){
          	x=2;
           	
           break;
		}
        cont++;
    }
    Beep(1500,100);Beep(1200,150);Beep(750,200);Beep(1300,100);Beep(1000,1000);Beep(600,150);Beep(750,100);Beep(1300,300);
    mostrarh(tablero1, tablero2,3,9, bolsa[c-1],c,x,acum1,acum2,indice1,indice2,numerosok1,numerosok2,cont);
	Color(blanco,negro);
	gotoxy(0,29);cout<<endl;

	if(x==1)
		ok = grabarDatos(alias1,"Horizontal",acum1);
	else if(x==2)
		ok = grabarDatos(alias2,"Horizontal",acum2);
	if (ok == 1){
		cout << "Error en el archivo..." << endl;
	}
	Sleep(1000);
	
}

bool revisartableroh(int numero,int **m,int ren,int col,int *v,int  &indice,int &acum){
    bool exito=false;
    bool bandera;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
            if(m[i][j]==numero){
                v[indice]=numero;
                indice++;
                acum=acum+numero;
                m[i][j]=0;
                exito=revisarsiganah(m,3,9);
                if(exito==true){
                    return true;
                }
            }
    }
}
    return false;
}

bool revisarsiganah(int **m,int ren, int col){
    bool bandera=false;
    int cont;
    
    for(int i=0;i<ren;i++){
        cont=0;
        for(int j=0;j<col;j++){
            if(m[i][j]==0){
                cont++;
            }else
            	break;
        }
        if(cont==9){
            bandera=true;
            break;
        }
    }
    return bandera;
}

void mostrarh(int** tablero1, int** tablero2, int ren, int col, int numero, int contador,int x,int acum1,int acum2, int indice1,int indice2,int*vector1,int*vector2, int cont){
	srand(time(NULL));
	int color, color1;
	int *numacum;
	int vector3[105];
	numacum=new int[100];
	
	color1=0+rand()%(14-1+1);
	Color(blanco, color1);
	gotoxy(52,2);printf("\332");Sleep(25);
	for(int i=53; i<69; i++){
		gotoxy(i,2);printf("\304");Sleep(25);
	}
	gotoxy(69,2);printf("\277");Sleep(25);
	gotoxy(69,3);printf("\263");Sleep(25);
	gotoxy(69,4);printf("\331");Sleep(25);
	for(int i=68; i>52; i--){
		gotoxy(i,4);printf("\304");Sleep(25);
	}
	gotoxy(52,4);printf("\300");Sleep(25);
	gotoxy(52,3);printf("\263");Sleep(25);
	
	color=0+rand()%(14-1+1);
	Color(blanco, color);
	gotoxy(53, 3); cout << "M"; Sleep(10);
	gotoxy(54, 3); cout << "o"; Sleep(10);
	gotoxy(55, 3); cout << "d"; Sleep(10);
	gotoxy(56, 3); cout << "o"; Sleep(10);
	gotoxy(57, 3); cout << " "; Sleep(10);
	gotoxy(58, 3); cout << " "; Sleep(10);
	gotoxy(59, 3); cout << "H"; Sleep(10);
	gotoxy(60, 3); cout << "o"; Sleep(10);
	gotoxy(61, 3); cout << "r"; Sleep(10);
	gotoxy(62, 3); cout << "i"; Sleep(10);
	gotoxy(63, 3); cout << "z"; Sleep(10);
	gotoxy(64, 3); cout << "o"; Sleep(10);
	gotoxy(65, 3); cout << "n"; Sleep(10);
	gotoxy(66, 3); cout << "t"; Sleep(10);
	gotoxy(67, 3); cout << "a"; Sleep(10);
	gotoxy(68, 3); cout << "l"; Sleep(10);

	Color(blanco, negro);
	
	gotoxy(10, 6); cout << "Numero generado: "<<numero; 
	Sleep(200);
	gotoxy(70, 6); cout << "Contador de numeros: "<<contador; 
	
	gotoxy(10,8);cout<<"Jugador 1: "<<alias1;
	gotoxy(10, 9); cout << "Aciertos: "<<indice1;
	gotoxy(10, 10); cout << "Lista de numeros: ";
	gotoxy(9, 11);
	for (int i = 0; i < indice1; i++)
	{
		cout <<setw(3) <<vector1[i]<<",";
			}
	gotoxy(70,8);cout<<"Jugador 2: "<<alias2;
	gotoxy(70, 9); cout << "Aciertos: "<<indice2;
	gotoxy(70, 10); cout << "Lista de numeros: ";
	gotoxy(69, 11);
	for (int i = 0; i < indice2; i++)
	{
		cout <<setw(3) <<vector2[i]<<",";
			}
	if(x == 1)
	{
		gotoxy(10,21);cout<<"Felicidades "<<alias1<<"!";
		gotoxy(70, 21); cout << "Acumulaste: "<<acum1<<" puntos";
	}
	else if(x == 2)
	{
		gotoxy(10,21);cout<<"Felicidades "<<alias2<<"!";
		gotoxy(62, 21); cout << "Acumulaste: "<<acum2<<" puntos";
	}
	
	gotoxy(0, 23); cout << "Todos los numeros que han salido: ";
	gotoxy(0, 24);
	vector3[cont]=numero;
	for (int i = 0; i < cont+1; i++)
	{
		cout <<setw(3)<<vector3[i]<<",";
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j< 9; j++)
		{
			if(tablero1[i][j]==0)
			{
				Color(amarillo, negro);
			}
			else
			{
				Color(blanco, negro);
			}
			gotoxy(10 + j * 5, 14 + i); printf(" %d ", tablero1[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Sleep(25);
			if(tablero2[i][j]==0)
			{
				Color(amarillo, negro);
			}
			else
			{
				Color(blanco, negro);
			}
			gotoxy(70 + j * 5, 14 + i); printf(" %d ", tablero2[i][j]);
		}
		cout << endl;
	}
	Color(negro, blanco);
	
}

void Color(int Background, int Text) {

	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	int    New_Color = Text + (Background * 16);

	SetConsoleTextAttribute(Console, New_Color);
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void textcolor(int n){ //--------------------------------------------------------------------------------------------------------------------
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n); 
}

