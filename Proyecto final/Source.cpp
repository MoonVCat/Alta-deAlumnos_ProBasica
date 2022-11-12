//¡Hola!, aqui les mostrare mi proyecto final para PB, es una lista de alumnos

//Bibliotecas usadas
#include <conio.h> //Para _getch()
#include <iostream> //Para cin y cout, input y output
#include <string.h> //Para funciones string
#include <ctype.h> //Para isdigit e isalpha
#include <windows.h> //Para Sleep()
#include <fstream>
#include <string> //para to_string

/*Se usa para los cin y cout, si no lo usaramos tendriamos que hacer std::cout y std::cin 
respectivamente */
using namespace std;

//Variables y arreglos utilizados <
int i = 0, matri = 1, p = 0, u, entomatadas;
int amb, j, cant, esp, agus, mimo, pregu, compermiso;
char entrada, preg[5], tele[20];
char apel[30], name[30], correoel[30];
int abc, ruf, contpunt, patada;
float yogurt, califi;
float fafa1, fafa2, fafa3, fafamux, fafamax;
string entomat;
string school;
string balon;

//Las funciones
char menu();            void case1(); 
void nom();             void tel();       
void email();           void mat();      
void domicilio();       void semestres();  
void calificaciones();  void case2();
void nom2();            void mat2();
void tel2();            void email2();
void domicilio2();      void semestres2();
void calificaciones2(); void case3();
void case4();           void case5();         

//La estructura alumnos
struct alumnos {

	int matricula;
	char apellido[30], domicilio[70];
	char correo[30], nombre[30];
	char semestre[10], telefono[20];
	char mater[20];
	float calif1, calif2, calif3, promedio;
	
} est[200];

//Donde se ubica el menu y el switch
void main() {
	/*El menú principal, haremos un do while, donde mientras la opcion sea != 6, seguiremos
	repitiendo el ciclo del menu */

	//----------------------------------------------------------------
	ofstream Archivo("Alumno.txt");
	Archivo.open("Alumno.txt", ios::out);    //Para el archivo de texto, se crea
	if (!Archivo) {
		cout << "\n\tNo hay archivo" << endl;
	}
	Archivo.close();
	//----------------------------------------------------------------

	if (i == 0) est[0].matricula = 0;

	do {
		system("CLS");

		cout << "\n\n\t\tMenu principal" << endl;
		cout << "\n\t\t1. Alta de alumnos" << endl;
		cout << "\n\t\t2. Edicion de alumnos" << endl;
		cout << "\n\t\t3. Borrar alumno" << endl;
		cout << "\n\t\t4. Lista de alumnos y calificaciones" << endl;
		cout << "\n\t\t5. Salir" << endl;
		
		entrada = menu(); //Entraremos a la funcion del menu para validarlo

		system("CLS");

		switch (entrada) {

		case '1': {

			case1(); //Entraremos a la funcion del caso 1
			break; }

		case '2': { 

			case2(); //Funcion del caso 2
			break; }

		case '3': { 

			case3(); //Funcion del caso 3
			break; }

		case '4': { 

			case4(); //Funcion del caso 4
			break; }

		case '5': { 
			
			case5(); //Funcion del caso 5(Archivo de texto)
			cout << "\n\t\tSaliendo..." << endl;
		   }
		}
	} while (entrada != '5');

	system("pause");
}

//Las funciones del programa y de los casos del switch
char menu() {
	int pow = 0;
	char opcion[10], c = 0;

	cout << "\n\t\tElige una opcion" << endl;
    cin >> opcion;

	cant = strlen(opcion);

	if (cant == 1) {
		if (isdigit(opcion[0]) != 0) pow = 1; //Verificara que todos sean enteros
	}
		if (pow == 1) c = opcion[0];

	return c;
}

void case1() {
	cout << "\n\t\t\nEn Alta de alumnos: Al entrar a esta ";
	cout << "\n\t\t opcion ingresaras primeramente los nombres y apellidos del ";
	cout << "\n\t\t alumno, despues se le dara automaticamente una matricula";
	cout << "\n\t\t que sera unica e irrepetible.";
	cout << "\n\t\t En seguida tendra que ingresar el nombre de la materia ";
	cout << "\n\t\t y 3 calificaciones con decimales, estos automaticamente";
	cout << "\n\t\t se modificaran para que solo se quede con dos decimales.";
	cout << "\n\t\t Luego tendra que escribir un telefono que sea mayor de 8 ";
	cout << "\n\t\t caracteres y menor de 12. ";
	cout << "\n\t\t Despues en el correo, el dominio obligatorio es @hotmail.com";
	cout << "\n\t\t por lo que usted solo necesita escribir los datos o numeros";
	cout << "\n\t\t antes del @.";
	cout << "\n\t\t Finalmente ingresara el semestre en el que se presenta el";
	cout << "\n\t\t alumno y el domicilio." << endl;
	cout << "\n\tPresione una tecla para continuar en alta de alumnos";
	_getch();

	do {
		system("CLS");

		patada = 2;
		cout << "\n\n\t¿Se equivoco de opcion? Si(1)/No(2)" << endl;
		cin >> balon;

		cant = size(balon);

		if (cant == 1) {
			for (j = 0; j < cant; j++) {

				if (isdigit(balon[j]) == 0) patada = 1;
			}
		}
		else patada = 1;

		if (patada == 1) cout << "\n\nOpcion no valida";
		_getch();
	} while (patada == 1);

	compermiso = stoi(balon);

	switch (compermiso) {
	case 2: {
		do {
			system("CLS");
			nom(); //Funcion del nombre

			system("CLS");
			mat(); //Funcion de la matricula

			system("CLS");
			calificaciones(); //Funcion de las calificaciones

			system("CLS");
			tel(); //Funcion del telefono

			system("CLS");
			email(); //Funcion del correo

			system("CLS");
			semestres(); //Funcion del semestre

			system("CLS");
			domicilio(); //Funcion del domicilio

			i++;
			do {
				system("CLS");

				patada = 2;
				cout << "\n\n¿Desea agregar otro alumno Si(1)/No(2)?" << endl;
				cin >> balon;

				cant = size(balon);

				if (cant == 1) {
					for (j = 0; j < cant; j++) {

						if (isdigit(balon[j]) == 0) patada = 1;
					}
				}
				else patada = 1;

				if (patada == 1) cout << "\n\nOpcion no valida";
				_getch();
			} while (patada == 1);

			pregu = stoi(balon);
		} while (pregu == 1);
		break;
	  }
	case 1: main();
	}
} 

void nom() {
	int m = 0, amn = 0;

	do {
		amn = 0;

		system("CLS");
		cout << "\n\t\t1. Alta de alumnos" << endl;
		cout << "\n\t\t Ingrese nombre/s de alumno" << endl;
		cin.ignore();
		cin.getline(name, 30);

		cant = strlen(name);

		for (m = 0; m < cant; m++) {

			if ((isalpha(name[m])||isspace(name[m])) == 0) amn = 1;
		}
		if (amn == 1) cout << "\n\tNombre invalido" << endl;
	} while (amn == 1);

	do {
		cout << "\n\n\t\t Ingrese apellido/s de alumno" << endl;
		cin.ignore();
		cin.getline(apel, 30);

		cant = strlen(apel);

		amn = 0;

		for (m = 0; m < cant; m++) {
			                            //Retornara igual a cero si no es una letra 
			if ((isalpha(apel[m]) || isspace(apel[m])) == 0) amn = 1;
		}
		if (amn == 1) cout << "\n\tApellido invalido" << endl;
	} while (amn == 1);

	strcpy_s(est[i].nombre,name);
	strcpy_s(est[i].apellido,apel);
}

void mat() {
	cout << "\n\t\t1. Alta de alumnos" << endl;
	cout << "\n\t\tGeneracion de matricula actual: " << matri;
	cout << "\n\t\tClick para continuar" << endl;
	_getch();

	do {
		amb = 2;
		for (j = 0; j < i; j++) {
			if (est[j].matricula == matri) {
				amb = 1;
				cout << "\n\n\n\t\tLa matricula ya se encuentra" << endl;
				_getch();
			}
		}
		system("CLS");
		if (amb == 1) {
			cout << "\n\tSe ingresara la matricula automaticamente" << endl;
			cout << "\n\tMatricula anterior: " << matri << endl;
			matri++;
			cout << "\tMatricula nueva: " << matri << endl;
		}
		_getch();
	} while (amb == 1);

	est[i].matricula = matri;
	matri++;
}

void calificaciones() {
	system("CLS");

	cout << "\n\t\t1. Alta de alumnos" << endl;
	cout << "\t\tIngrese el nombre de la materia " << endl;
	cin >> est[i].mater;

	do {
		do {
			system("CLS");

			ruf = 2;
			mimo = 2;
			contpunt = 0;
			cout << "\n\t\t1. Alta de alumnos" << endl;
			cout << "\n\t\tMateria: " << est[i].mater << endl;
			cout << "\tIngrese calificacion 1 con decimales" << endl;
			cin >> school;

			cant = size(school);

			for (j = 0; j < cant; j++) {

				if (isdigit(school[j]) == 0) ruf = 1;
			}
			for (j = 0; j < cant; j++) {

				if (school[j] == 46) {
					contpunt++;
					ruf = 2;
				}
			}
			if (contpunt != 1) ruf = 1;
			if (ruf == 1) cout << "\n\n\tValor ingresado no valido";
			_getch();

		} while (ruf == 1);

		califi = stof(school);

		if (califi >= 0.0 && califi <= 100.0) {

			abc = 100 * califi;
			yogurt = abc * 1.0 / 100;
		}
		else {
			cout << "\n\tValor ingresado no valido" << endl;
			mimo = 1;
			_getch();
		}
	} while (mimo == 1);

	cout << "\n\tLa calificacion 1 es: " << yogurt << endl;
	est[i].calif1 = yogurt;
	Sleep(800);

	system("CLS");
	do {
		do{
		system("CLS");

		ruf = 2;
		contpunt = 0;
		mimo = 2;
		cout << "\n\t\t1. Alta de alumnos" << endl;
		cout << "\n\t\tMateria: " << est[i].mater << endl;
		cout << "\tIngrese calificacion 2 con decimales" << endl;
		cin >> school;

		cant = size(school);

		for (j = 0; j < cant; j++) {

			if (isdigit(school[j]) == 0) ruf = 1;
		}
		for (j = 0; j < cant; j++) {

			if (school[j] == 46) {
				contpunt++;
				ruf = 2;
			}
		}
		if (contpunt != 1) ruf = 1;
		if (ruf == 1) cout << "\n\n\tValor ingresado no valido";
		_getch();
	} while (ruf == 1);

	califi = stof(school);

		if (califi >= 0.0 && califi <= 100.0) {

			abc = 100 * califi;
			yogurt = abc * 1.0 / 100;
		}
		else {
			cout << "\n\tValor ingresado no valido" << endl;
			mimo = 1;
			_getch();
		}
	} while (mimo == 1);

	cout << "\n\tLa calificacion 2 es: " << yogurt << endl;
	est[i].calif2 = yogurt;
	Sleep(800);

	system("CLS");
	do {
		do{
		system("CLS");

		ruf = 2;
		contpunt = 0;
		mimo = 2;
		cout << "\n\t\t1. Alta de alumnos" << endl;
		cout << "\n\t\tMateria: " << est[i].mater << endl;
		cout << "\tIngrese calificacion 3 con decimales" << endl;
		cin >> school;

		cant = size(school);

		for (j = 0; j < cant; j++) {

			if (isdigit(school[j]) == 0) ruf = 1;
		}
		for (j = 0; j < cant; j++) {

			if (school[j] == 46) {
				contpunt++;
				ruf = 2;
			}
		}
		if (contpunt != 1) ruf = 1;
		if (ruf == 1) cout << "\n\n\tValor ingresado no valido";
		_getch();

		} while (ruf == 1);

		califi = stof(school);

		if (califi >= 0.0 && califi <= 100.0) {

			abc = 100 * califi;
			yogurt = abc * 1.0 / 100;
		}
		else {
			cout << "\n\tValor ingresado no valido" << endl;
			mimo = 1;
			_getch();
		}
	} while (mimo == 1);

	cout << "\n\tLa calificacion 3 es: " << yogurt << endl;
	est[i].calif3 = yogurt;
	Sleep(800);

	system("CLS");

	fafa1 = est[i].calif1 *0.30;
	fafa2 = est[i].calif2 *0.45;
	fafa3 = est[i].calif3 *0.25;
	fafamux = fafa1 + fafa2 + fafa3;

	abc = 100 * fafamux;
	fafamax = abc * 1.0 / 100;

	cout << "\n\n\n\n\tTiene un promedio de: " << fafamax << endl;
	est[i].promedio = fafamax;
	Sleep(1000);
}

void tel() {
	int amn = 0;

	do {
		system("CLS");

		cout << "\n\t\t1. Alta de alumnos" << endl;
		cout << "\n\t\t Ingrese telefono" << endl;
		amn = 0;
		cin >> tele;

		//Checaremos si esta en el rango esperado
		if (strlen(tele) < 8) {
			cout << "\n\t8 digitos minimo ";
			amn = 1;
		}
		else if (strlen(tele) > 12) {
			cout << "\n\t12 digitos maximo ";
			amn = 1;
		}
		cant = (strlen(tele));

		for (j = 0; j < cant; j++) {

			if (isdigit(tele[j]) == 0) amn = 1;
		}
		if (amn == 1) cout << "\n\tEl telefono es invalido" << endl;
	} while (amn == 1);

	strcpy_s(est[i].telefono, tele);
} 

void email() {
	int pen = 0;

	do {
		int t, contpunto = 0, contarroba = 0;
		int contarr = 0, contpun = 0, manzana = 0;

		system("CLS");
		
		cout << "\n\t\t1. Alta de alumnos" << endl;
		cout << "\n\n\t\tEl dominio obligatorio sera: @hotmail.com" << endl;
		cout << "\t\t Ingrese correo electronico" << endl;
		cin >> correoel;

		strcat_s(correoel, "@hotmail.com");

		for (t = 0; correoel[t] != NULL; t++) {
			if (correoel[t] == '@') {
				contarr = t;
				contarroba++;
			}
			if (correoel[t] == '.') {
				contpun = t;
				contpunto++;
			}
		}
		if (contarroba > 1) {
			cout << "Solo se permite un @" << endl;
			pen = 1;
		}
		if (contpunto > 1) {
			cout << "Solo se permite un ." << endl;
			pen = 1;
		}
		if (contarroba == 1 && contpunto == 1) pen = 0;
	} while (pen == 1);

	cout << "\n\tEl correo aceptado es: " << correoel << endl;
	Sleep(800);

	strcpy_s(est[i].correo, correoel);
} 

void semestres() {
	char sem[10];
	int torta = 0, durazno;

	do {
		system("CLS");

		durazno = 0;
		cout << "\n\t\t1. Alta de alumnos" << endl;
		cout << "\n\t\tIngrese semestre del alumno" << endl;
		cin >> sem;

		torta = strlen(sem);

		for (j = 0; j < torta; j++) {

			if (isdigit(sem[j]) == 0) durazno = 1;
		}
		if (durazno == 1) cout << "Opcion invalida" << endl;
	} while (durazno == 1);

	strcpy_s(est[i].semestre, sem);
}

void domicilio() {

	cout << "\n\t\t1. Alta de alumnos" << endl;
	cout << "\n\t\tAlta de domicilio" << endl;
	cout << "\t\tIngrese numero de casa, calle y colonia" << endl;
	cin.ignore();
	cin.getline(est[i].domicilio, 70);
}

void case2() {
	int tacos = 0, plus;
	cout << "\n\t\t\nEn edicion de alumnos: Ingresara la matricula del alumno que usted";
	cout << "\n\t\t desea buscar para editar, despues de eso, usted decidira que";
	cout << "\n\t\t campos quiere modificar, ya sea solo nombre y apellidos, ";
	cout << "\n\t\t o todo, al terminar de modificar lo que desea se imprimira al ";
	cout << "\n\t\t alumno con los nuevos datos que usted modifico" << endl;
	cout << "\n\tPresione una tecla para continuar en edicion de alumnos";
	_getch();

	do {
		system("CLS");

		patada = 2;
		cout << "\n\n\t¿Se equivoco de opcion? Si(1)/No(2)" << endl;
		cin >> balon;

		cant = size(balon);

		if (cant == 1) {
			for (j = 0; j < cant; j++) {

				if (isdigit(balon[j]) == 0) patada = 1;
			}
		}
		else patada = 1;

		if (patada == 1) cout << "\n\nOpcion no valida";
		_getch();
	} while (patada == 1);

	compermiso = stoi(balon);

	switch (compermiso) {
	case 2: {
		do {
			do {
				do {
					system("CLS");

					cout << "\n\t\t2. Edicion de alumnos" << endl;

					cout << "\n\t\tMatriculas actuales" << endl;
					for (j = 0; j < i; j++) {
						cout << "\t\t" << est[j].matricula << "\n";
					}
					cout << "\n\t\tIngrese la matricula del alumno que desee editar" << endl;
					cin >> entomat;
					agus = 2;
					plus = 2;

					cant = size(entomat);

					for (j = 0; j < cant; j++) {
						if (isdigit(entomat[j]) == 0) plus = 1;
					}
					if (plus == 1) cout << "\n\n\tValor ingresado no valido" << endl;

				} while (plus == 1);

				entomatadas = stoi(entomat);

				for (j = 0; j <= i - 1; j++) {

					if (entomatadas == est[j].matricula) agus = 1;
				}
				if (agus != 1) agus = 2;

				if (agus == 2) cout << "\n\tMatricula no encontrada" << endl;
				_getch();
			} while (agus == 2);

			for (j = 0; j < i; j++) {
				if (entomatadas == est[j].matricula) {
					p = j;
				}
			}
			cout << "\n\t\tLa matricula elegida corresponde al siguiente alumno" << endl;
			cout << "\n\tNombre/s y apellido/s: " << est[p].nombre << " " << est[p].apellido << endl;
			cout << "\tMatricula: " << est[p].matricula << endl;
			cout << "\tMateria: " << est[p].mater << endl;
			cout << "\tCalificacion 1: " << est[p].calif1 << endl;
			cout << "\tCalificacion 1: " << est[p].calif2 << endl;
			cout << "\tCalificacion 1: " << est[p].calif3 << endl;
			cout << "\tPromedio: " << est[p].promedio << endl;
			cout << "\tTelefono: " << est[p].telefono << endl;
			cout << "\tCorreo electronico: " << est[p].correo << endl;
			cout << "\tSemestre: " << est[p].semestre << endl;
			cout << "\tDireccion: " << est[p].domicilio << endl;

			Sleep(4000);
			do {
				system("CLS");
				cout << "\n\t\t¿Que desea editar?, Seleccione la opcion deseada" << endl;
				cout << "\n\t\t1. Nombre/s y apellido/s de alumno" << endl;
				cout << "\n\t\t2. Matricula" << endl;
				cout << "\n\t\t3. Calificaciones" << endl;
				cout << "\n\t\t4. Telefono" << endl;
				cout << "\n\t\t5. Correo electronico" << endl;
				cout << "\n\t\t6. Semestre" << endl;
				cout << "\n\t\t7. Direccion" << endl;
				cout << "\n\t\t8. Todo" << endl;
				cin >> tacos;

				switch (tacos) {
				case 1: {

					system("CLS");
					nom2(); //Se repetira la funcion del nombre pero esta vez para editar
					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\n\tNombre/s y apellido/s: " << est[p].nombre << " " << est[p].apellido << endl;
					Sleep(1000);
					break; }
				case 2: {

					system("CLS");
					mat2();
					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\tMatricula: " << est[p].matricula << endl;
					Sleep(1000);
					break; }
				case 3: {

					system("CLS");
					calificaciones2();
					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\tMateria: " << est[p].mater << endl;
					cout << "\tCalificacion 1: " << est[p].calif1 << endl;
					cout << "\tCalificacion 1: " << est[p].calif2 << endl;
					cout << "\tCalificacion 1: " << est[p].calif3 << endl;
					cout << "\tPromedio: " << est[p].promedio << endl;
					Sleep(2000);
					break; }
				case 4: {

					system("CLS");

					tel2();
					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\tTelefono: " << est[p].telefono << endl;
					Sleep(1000);
					break; }
				case 5: {

					system("CLS");
					email2();
					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\tCorreo electronico: " << est[p].correo << endl;
					Sleep(1000);
					break; }
				case 6: {

					system("CLS");
					semestres2();
					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\tSemestre: " << est[p].semestre << endl;
					Sleep(1000);
					break; }
				case 7: {

					system("CLS");
					domicilio2();
					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\tDireccion: " << est[p].domicilio << endl;
					Sleep(1000);
					break; }
				case 8: {

					system("CLS");
					nom2();
					system("CLS");
					mat2();
					system("CLS");
					calificaciones2();
					system("CLS");
					tel2();
					system("CLS");
					email2();
					system("CLS");
					semestres2();
					system("CLS");
					domicilio2();

					system("CLS");

					cout << "\n\tEstos son las ediciones nuevas: " << endl;
					cout << "\n\tNombre/s y apellido/s: " << est[p].nombre << " " << est[p].apellido << endl;
					cout << "\tMatricula: " << est[p].matricula << endl;
					cout << "\tMateria: " << est[p].mater << endl;
					cout << "\tCalificacion 1: " << est[p].calif1 << endl;
					cout << "\tCalificacion 1: " << est[p].calif2 << endl;
					cout << "\tCalificacion 1: " << est[p].calif3 << endl;
					cout << "\tPromedio: " << est[p].promedio << endl;
					cout << "\tTelefono: " << est[p].telefono << endl;
					cout << "\tCorreo electronico: " << est[p].correo << endl;
					cout << "\tSemestre: " << est[p].semestre << endl;
					cout << "\tDireccion: " << est[p].domicilio << endl;
					Sleep(3000);
					break; }
				}
				do {
					system("CLS");

					patada = 2;
					cout << "\t¿Desea editar otro campo Si(1)/No(2)?" << endl;
					cin >> balon;

					cant = size(balon);

					if (cant == 1) {
						for (j = 0; j < cant; j++) {

							if (isdigit(balon[j]) == 0) patada = 1;
						}
					}
					else patada = 1;

					if (patada == 1) cout << "\n\nOpcion no valida";
					_getch();

				} while (patada == 1);

				pregu = stoi(balon);
			} while (pregu == 1);

			//Alumno nuevo
			cout << "\n\tEstos son las ediciones nuevas: " << endl;
			cout << "\n\tNombre/s y apellido/s: " << est[p].nombre << " " << est[p].apellido << endl;
			cout << "\tMatricula: " << est[p].matricula << endl;
			cout << "\tMateria: " << est[p].mater << endl;
			cout << "\tCalificacion 1: " << est[p].calif1 << endl;
			cout << "\tCalificacion 1: " << est[p].calif2 << endl;
			cout << "\tCalificacion 1: " << est[p].calif3 << endl;
			cout << "\tPromedio: " << est[p].promedio << endl;
			cout << "\tTelefono: " << est[p].telefono << endl;
			cout << "\tCorreo electronico: " << est[p].correo << endl;
			cout << "\tSemestre: " << est[p].semestre << endl;
			cout << "\tDireccion: " << est[p].domicilio << endl;
			Sleep(3000);
			do {
				system("CLS");

				patada = 2;
				cout << "\t¿Desea editar otro alumno Si(1)/No(2)?" << endl;
				cin >> balon;

				cant = size(balon);

				if (cant == 1) {
					for (j = 0; j < cant; j++) {

						if (isdigit(balon[j]) == 0) patada = 1;
					}
				}
				else patada = 1;

				if (patada == 1) cout << "\n\nOpcion no valida";
				_getch();

			} while (patada == 1);

			pregu = stoi(balon);
		} while (pregu == 1);
		break;
	  }
	  case 1: main();
	}
}

void nom2() {
	int m = 0, amn = 0;

	do {
		amn = 0;

		cout << "\n\n\t\t Ingrese nombre/s de alumno" << endl;
		cin.ignore();
		cin.getline(name, 30);

		cant = strlen(name);

		for (m = 0; m < cant; m++) {

			if ((isalpha(name[m]) || isspace(name[m])) != 0) m++;
			else amn = 1;
		}
		if (amn == 1) cout << "\n\n\tNombre invalido" << endl;
	} while (amn == 1);

	do {
		cout << "\n\n\t\t Ingrese apellido/s de alumno" << endl;
		cin.ignore();
		cin.getline(apel, 30);

		cant = strlen(apel);

		amn = 0;

		for (m = 0; m < cant; m++) {

			if ((isalpha(apel[m]) || isspace(apel[m])) != 0) m++;
			else amn = 1;
		}
		if (amn == 1) cout << "\n\n\tApellido invalido" << endl;
	} while (amn == 1);

	strcpy_s(est[p].nombre, name);
	strcpy_s(est[p].apellido, apel);
}

void mat2() {
    cout << "\n\t\tMatricula actual: " << est[p].matricula << endl;
	cout << "\n\t\tClick para continuar" << endl;
	Sleep(800);

	matri++;
	do {
		amb = 2;
		for (j = 0; j < i; j++) {
			if (est[j].matricula == matri) {
				amb = 1;
				cout << "\n\n\n\t\tLa matricula ya se encuentra" << endl;
				_getch();
			}
		}
		system("CLS");
		if (amb == 1) {
			cout << "\n\tSe ingresara la matricula automaticamente" << endl;
			cout << "\n\tMatricula anterior: " << matri << endl;
			matri++;
			cout << "\tMatricula nueva: " << matri << endl;
		}
		_getch();
	} while (amb == 1);

	cout << "\n\t\tNueva matricula: " << matri << endl;
	Sleep(800);

	est[p].matricula = matri;
}

void calificaciones2() {
	system("CLS");

	cout << "\t\tIngrese nuevo nombre de la materia" << endl;
	cin >> est[p].mater;

	do {
		do{
		system("CLS");

		ruf = 2;
		contpunt = 0;
		mimo = 2;
		cout << "\n\t\tMateria: " << est[p].mater << endl;
		cout << "\tIngrese calificacion 1 con decimales" << endl;
		cin >> school;

		cant = size(school);

		for (j = 0; j < cant; j++) {

			if (isdigit(school[j]) == 0) ruf = 1;
		}
		for (j = 0; j < cant; j++) {

			if (school[j] == 46) {
				contpunt++;
				ruf = 2;
			}
		}
		if (contpunt != 1) ruf = 1;
		if (ruf == 1) cout << "\n\n\tValor ingresado no valido";
		_getch();

		} while (ruf == 1);

		califi = stof(school);

		if (califi >= 0.0 && califi <= 100.0) {

			abc = 100 * califi;
			yogurt = abc * 1.0 / 100;
		}
		else {
			cout << "\n\tValor ingresado no valido" << endl;
			mimo = 1;
			_getch();
		}
	} while (mimo == 1);

	cout << "\n\tLa calificacion 1 es: " << yogurt << endl;
	est[p].calif1 = yogurt;
	Sleep(800);

	system("CLS");
	do {
		do{
		system("CLS");

		ruf = 2;
		contpunt = 0;
		mimo = 2;
		cout << "\n\t\tMateria: " << est[p].mater << endl;
		cout << "\tIngrese calificacion 2 con decimales" << endl;
		cin >> school;

		cant = size(school);

		for (j = 0; j < cant; j++) {

			if (isdigit(school[j]) == 0) ruf = 1;
		}
		for (j = 0; j < cant; j++) {

			if (school[j] == 46) {
				contpunt++;
				ruf = 2;
			}
		}
		if (contpunt != 1) ruf = 1;
		if (ruf == 1) cout << "\n\n\tValor ingresado no valido";
		_getch();

		} while (ruf == 1);

		califi = stof(school);

		if (califi >= 0.0 && califi <= 100.0) {

			abc = 100 * califi;
			yogurt = abc * 1.0 / 100;
		}
		else {
			cout << "\n\tValor ingresado no valido" << endl;
			mimo = 1;
			_getch();
		}
	} while (mimo == 1);

	cout << "\n\tLa calificacion 2 es: " << yogurt << endl;
	est[p].calif2 = yogurt;
	Sleep(800);

	system("CLS");
	do {
		do{
		system("CLS");

		ruf = 2;
		contpunt = 0;
		mimo = 2;
		cout << "\n\t\tMateria: " << est[p].mater << endl;
		cout << "\tIngrese calificacion 3 con decimales" << endl;
		cin >> school;

		cant = size(school);

		for (j = 0; j < cant; j++) {

			if (isdigit(school[j]) == 0) ruf = 1;
		}
		for (j = 0; j < cant; j++) {

			if (school[j] == 46) {
				contpunt++;
				ruf = 2;
			}
		}
		if (contpunt != 1) ruf = 1;
		if (ruf == 1) cout << "\n\n\tValor ingresado no valido";
		_getch();

		} while (ruf == 1);

		califi = stof(school);

		if (califi >= 0.0 && califi <= 100.0) {

			abc = 100 * califi;
			yogurt = abc * 1.0 / 100;
		}
		else {
			cout << "\n\tValor ingresado no valido" << endl;
			mimo = 1;
			_getch();
		}
	} while (mimo == 1);

	cout << "\n\tLa calificacion 3 es: " << yogurt << endl;
	est[p].calif3 = yogurt;
	Sleep(800);

	system("CLS");

	fafa1 = est[p].calif1 *0.30;
	fafa2 = est[p].calif2 *0.45;
	fafa3 = est[p].calif3 *0.25;
	fafamux = fafa1 + fafa2 + fafa3;

	abc = 100 * fafamux;
	fafamax = abc * 1.0 / 100;

	cout << "\n\n\n\n\tTiene un promedio de: " << fafamax << endl;
	est[p].promedio = fafamax;
	Sleep(1000);
}

void tel2() {
	int amn = 0;

	do {
		cout << "\n\n\t\t Ingrese telefono" << endl;
		amn = 0;
		cin >> tele;

		//Checaremos si esta en el rango esperado
		if (strlen(tele) < 8) {
			cout << "\n\n\t8 digitos minimo " << endl;
			amn = 1;
		}
		else if (strlen(tele) > 12) {
			cout << "\n\n\t12 digitos maximo " << endl;
			amn = 1;
		}
		cant = (strlen(tele));

		for (j = 0; j < cant; j++) {

			if (isdigit(tele[j]) == 0) amn = 1;
		}
		if (amn == 1) cout << "\n\tEl telefono es invalido" << endl;
	} while (amn == 1);

	strcpy_s(est[p].telefono, tele);
}

void email2() {
	int pen = 0;

	do {
		int t, contpunto = 0, contarroba = 0;
		int contarr = 0, contpun = 0, manzana = 0;

		cout << "\n\n\t\tEl dominio obligatorio sera: @hotmail.com" << endl;
		cout << "\n\t\t Ingrese correo electronico" << endl;
		cin >> correoel;

		strcat_s(correoel, "@hotmail.com");

		for (t = 0; correoel[t] != NULL; t++) {
			if (correoel[t] == '@') {
				contarr = t;
				contarroba++;
			}
			if (correoel[t] == '.') {
				contpun = t;
				contpunto++;
			}
		}
		if (contarroba > 1) {
			cout << "Solo se permite un @" << endl;
			pen = 1;
		}
		if (contpunto > 1) {
			cout << "Solo se permite un ." << endl;
			pen = 1;
		}
		if (contarroba == 1 && contpunto == 1 ) pen = 0;
	} while (pen == 1);

	cout << "\n\tEl correo aceptado es: " << correoel << endl;
	_getch();

	strcpy_s(est[p].correo, correoel);
}

void semestres2() {
	char sem[10];
	int torta = 0, durazno = 0;

	do {
		durazno = 0;
		cout << "\n\n\t\tIngrese semestre del alumno" << endl;
		cin >> sem;

		torta = strlen(sem);

		for (j = 0; j < torta; j++) {

			if (isdigit(sem[j]) == 0) durazno = 1;
		}
		if (durazno == 1) cout << "Opcion invalida" << endl;
	} while (durazno == 1);

	strcpy_s(est[p].semestre, sem);
}

void domicilio2() {
	system("CLS");

	cout << "\n\n\t\tAlta de domicilio" << endl;
	cout << "\n\t\tIngrese numero de casa, calle y colonia" << endl;
	cin.ignore();
	cin.getline(est[p].domicilio, 70);

}

void case3() {
	int plus;
	int espregunta;
	cout << "\n\t\t\nEn borrar alumno: Hara lo mismo que en edicion de alumnos, ingresara";
	cout << "\n\t\t la matricula del alumno que usted desea borrar, y entonces se";
	cout << "\n\t\t borrara, automaticamente los demas alumnos se recorreran,";
	cout << "\n\t\t haciendo que el alumno siguiente se recorra al puesto en donde ";
	cout << "\t\t estaba el alumno eliminado y asi sucesivamente." << endl;
	cout << "\n\tPresione una tecla para continuar en borrar alumno";
	_getch();

	do {
		system("CLS");

		patada = 2;
		cout << "\n\n\t¿Se equivoco de opcion? Si(1)/No(2)" << endl;
		cin >> balon;

		cant = size(balon);

		if (cant == 1) {
			for (j = 0; j < cant; j++) {

				if (isdigit(balon[j]) == 0) patada = 1;
			}
		}
		else patada = 1;

		if (patada == 1) cout << "\n\nOpcion no valida";
		_getch();
	} while (patada == 1);

	compermiso = stoi(balon);

	switch (compermiso) {
	case 2: {
		do {
			do {
				do {
					system("CLS");

					cout << "\n\t\t3. Borrar alumno" << endl;

					cout << "\n\t\tMatriculas actuales" << endl;
					for (j = 0; j < i; j++) {
						cout << "\t\t" << est[j].matricula << "\n";
					}
					cout << "\n\t\tIngrese la matricula del alumno que desee borrar" << endl;
					cin >> entomat;
					agus = 2;
					plus = 2;

					cant = size(entomat);

					for (j = 0; j < cant; j++) {
						if (isdigit(entomat[j]) == 0) plus = 1;
					}
					if (plus == 1) cout << "\n\n\tValor ingresado no valido" << endl;
					_getch();

				} while (plus == 1);

				entomatadas = stoi(entomat);

				for (j = 0; j <= i - 1; j++) {

					if (entomatadas == est[j].matricula) agus = 1;
				}
				if (agus != 1) agus = 2;

				if (agus == 2) cout << "\n\tMatricula no encontrada" << endl;
				_getch();
			} while (agus == 2);

			for (j = 0; j < i; j++) {
				if (entomatadas == est[j].matricula) {
					p = j;
				}
			}
			cout << "\n\t\tLa matricula elegida corresponde al siguiente alumno" << endl;
			cout << "\n\tNombre/s y apellido/s: " << est[p].nombre << " " << est[p].apellido << endl;
			cout << "\tMatricula: " << est[p].matricula << endl;
			cout << "\tTelefono: " << est[p].telefono << endl;
			cout << "\tCorreo electronico: " << est[p].correo << endl;
			cout << "\tSemestre: " << est[p].semestre << endl;
			cout << "\tDireccion: " << est[p].domicilio << endl;
			Sleep(4000);

			cout << "\n\t\t¿Desea realmente eliminarlo? Si(1)/No(2)" << endl;
			cin >> espregunta;

			switch (espregunta) {

			case 1: {
				cout << "\n\tEl alumno sera eliminado..." << endl;
				Sleep(1000);

				for (j = p; j < i; j++) {
					est[j] = est[j + 1];
				}

				system("CLS");
				cout << "\n\t\tAlumno eliminado, se correran las posiciones automaticamente" << endl;
				Sleep(1000);
				break; }
			case 2: {
				main();
			}
			}
			system("CLS");
			cout << "\t¿Desea eliminar otro alumno Si(1)/No(2)" << endl;
			cin >> pregu;

		} while (pregu == 1);
		break;
	  }
	case 1: main();
	}
}

void case4() {
	cout << "\n\t\t\nEn lista de alumnos: se imprimiran a todos los alumnos registrados";
	cout << "\n\t\t con todos sus datos ingresados.";
	cout << "\n\tPresione una tecla para continuar en alta de alumnos";
	_getch();

	system("CLS");

	cout << "\n\t\t5. Lista de alumnos y calificaciones" << endl;

	for (j = 0; j < i; j++) {

		cout << "\n\n\tNombre/s y apellido/s: " << est[j].nombre << " " << est[j].apellido << endl;
		cout << "\tMatricula: " << est[j].matricula << endl;
		cout << "\tMateria: " << est[j].mater << endl;
		cout << "\tCalificacion 1: " << est[j].calif1 << endl;
		cout << "\tCalificacion 1: " << est[j].calif2 << endl;
		cout << "\tCalificacion 1: " << est[j].calif3 << endl;
		cout << "\tPromedio: " << est[j].promedio << endl;
		cout << "\tTelefono: " << est[j].telefono << endl;
		cout << "\tCorreo electronico: " << est[j].correo << endl;
		cout << "\tSemestre: " << est[j].semestre << endl;
		cout << "\tDireccion: " << est[j].domicilio << endl;
	}
	Sleep(10000);
}

void case5() {
	ofstream Archivo;
	Archivo.open("Alumno.txt", ios::out);

	for (j = 0; j < i; j++) {

		Archivo << "\n\n\tNombre/s y apellido/s: " << est[j].nombre << " " << est[j].apellido << endl;
		Archivo << "\tMatricula: " << est[j].matricula << endl;
		Archivo << "\tMateria: " << est[j].mater << endl;
		Archivo << "\tCalificacion 1: " << est[j].calif1 << endl;
		Archivo << "\tCalificacion 1: " << est[j].calif2 << endl;
		Archivo << "\tCalificacion 1: " << est[j].calif3 << endl;
		Archivo << "\tPromedio: " << est[j].promedio << endl;
		Archivo << "\tTelefono: " << est[j].telefono << endl;
		Archivo << "\tCorreo electronico: " << est[j].correo << endl;
		Archivo << "\tSemestre: " << est[j].semestre << endl;
		Archivo << "\tDireccion: " << est[j].domicilio << endl;
	}
	Archivo.close();
}