//EJERCICIO 1
//Imprimir tu nombre entre almohadillas con arrays
INICIAR
CADENA nombre[20];
ENTERO i;

IMPRIMIR("Introduce tu nombre");
LEER("%CADENA%", nombre);

DESDE(i = 0; i < LONGITUD(nombre) + 1; i++){
	IMPRIMIR("#")
{
IMPRIMIR("\n#"nombre"#\n");
DESDE(i = 0; i < LONGITUD(nombre) + 1; i++){
	IMPRIMIR("#")
{
FIN 0;


//EJERCICIO 2
//Pedir 10 numeros por teclado y decir si son los numeros del 0 al 9 sin repetir
INICIAR
ENTERO numeros[10];
ENTERO i;

IMPRIMIR("Introduce los numeros");
LEER("%ENTERO%", numeros);

DESDE(i = 0; i < ; i++){


FIN 0;

//EJERCICIO 3
//Pedir dos numeros q el tercero sea random del 1-4 y ese random el 1 suma 2 resta... los dos primeros numeros
INICIAR
ENTERO num1[20];
ENTERO num2[20];
factor = ALEATORIO(1, 4);

IMPRIMIR("Introduce el primer numero");
LEER("%ENTERO%", num1);

IMPRIMIR("Introduce el segundo numero");
LEER("%ENTERO%", num2);
IMPRIMIR(factor);

SI(factor == 1 || factor == 3){
	IMPRIMIR("Te ha tocado la suma");
	IMPRIMIR(num1 + num2);
{ SINO SI (factor == 2 || factor == 4){
	IMPRIMIR("Te ha tocado la resta");
	IMPRIMIR(num1 - num2);
	
FIN 0;
