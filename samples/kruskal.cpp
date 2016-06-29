#include <conio.h>
#include "algoritms.cpp"

typedef float typ;

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int z;
	FILE *myfile;
	cout << "Алгориитм Крускала" << endl;
	cout << "Введите тип приоритетной очереди: " << endl;
	cout << "1) d-куча" << endl;
	cout << "2) Бинарное деревo" << endl;
	cout << "3) таблица" << endl;
	cin >> z;
	system ("cls");
	int n;
	cout << "Введите количество вершин" << endl;		
	cin >> n;		
	cout << "Введите количество ребер" << endl;
	int m;
	cin >> m;

	Graph<typ> *graph = new Graph<typ> (n,m);
		
	int l;
	cout << "Будем генерировать граф (1), вручную (2)?" << endl;
	cin >> l;
	switch (l)
		{
	case 1:
		{
		cout << "Введите min и max значение веса" << endl;
		typ min, max;
		cin >> min;
		cin >> max;
		graph->createGraph(min, max);
		break;
		}
	case 2:
		{
			for (int i=0; i<m;i++)
		{
			cout << "Введите откуда, куда и вес" << endl;
			int a,b;
			typ c;
			cin >> a;
			cin >> b;
			cin >> c;
			graph->addEdge(a,b,c);
		}
		break;	
		}
	
	}
	
	system ("cls");

	cout << "Граф: " << endl<<endl;
	graph->print();
		
	cout << "Применяем алгоритм Крускала..." << endl;
	Graph<typ> *res = new Graph<typ> (n,m);
	graph->sort();
	
	PQueue<typ>* queue;
	int tmp2 = 0;
	if (z == 1)
		tmp2 = n;
	if (z == 3)
		tmp2 = m;
	make_queue<typ>::makeQueue(queue, z, tmp2);

	res = Algoritm<typ>::kruskal(graph, queue);
	cout << endl << endl;
	res->print();
}
