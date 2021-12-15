#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


//declare classes in advance
class Circle;
class Oval;
class Square;
class Rectangle;
class Triangle;

//abstract class of shapes
    class Shapes  {
    protected:
        static const int type1 = 0;
        static const int type2 = 1;
        static const int type3 = 2;
        static const int type4 = 3;
        static const int type5 = 4;
        virtual int getType() = 0;
        virtual void save(ofstream& file) = 0;
        virtual void load(ifstream& file) = 0;
    public:
        virtual double getCP() = 0;
        virtual void getDistance() = 0;
        virtual double getDistanceValue() = 0;
        virtual void getArea() = 0;
        virtual double getAreaValue() = 0;

        void writeToFile(ofstream& file) {
            save(file);
        }
        static Shapes* readFromFile(ifstream& file);
    };

    class Circle : public Shapes {
    private:
        double centPointX;
        double CPY;
        double Area;
        double Distance;
    protected:
        double radius1;
        int getType() override { return type1; }
        void save(ofstream& file) override {
            file << type1 << endl;
            file << radius1 << endl;
            file << Area << endl;
        }

        void load(ifstream& file) override {
            file >> Area;
        }
    public:
        Circle() { radius1 = 0; }
        Circle(double centPointX, double CPY, double radius1) { this->radius1 = radius1; this->centPointX = centPointX; this->CPY = CPY; }
        double getCP() override { 
            cout << "CP: (" << centPointX << "," << CPY << ")" << endl;
            return centPointX;
        }
        void setCPX(double value)  { centPointX = value; }
        void setCPY(double value)  { CPY = value; }
        double getRad1() const { return radius1; }
        void setRad1(double value) { radius1 = value; } 
        void getDistance() override {
          Distance = sqrt(pow(centPointX - 0, 2) + pow(CPY - 0, 2));
          cout << "Distance is: " << Distance << endl;
        }
        double getDistanceValue() override { return Distance; }
        void getArea() override
        {
            Area = (3.14 * (radius1 * radius1));
            cout << "Circle Area: " << Area << endl;
            
        }
        double getAreaValue() override { return Area; }
        
         
   };
    
    class Oval : public Circle {
    private:
        double radius2;
        double Area;
        double centPointX;
        double CPY;
        double Distance;
    protected:
        virtual int getType() override { return type2; }
        virtual void save(ofstream& file) override {
            file << type2 << endl;
            file << getRad1() << endl;
            file << radius2 << endl;
            file << Area << endl;
        }
        virtual void load(ifstream& file) override {
            int x;
            file >> x;
            setRad1(x);
            file >> radius2;
            file >> Area;
        }
        
    public:
        Oval() : Circle() { radius2 = 0; }
        Oval(double centPointX, double CPY, int radius2, int radius1) : Circle(centPointX, CPY, radius1) { this->radius2 = radius2; this->centPointX = centPointX; this->CPY = CPY; }
        double getRad2() const { return radius2; }
        void setRad2(double value) { radius2 = value; }
        double getCP() override {
            cout << "CP: (" << centPointX << "," << CPY << ")" << endl;
            return centPointX;
        }
        void setCPX(double value) { centPointX = value; }
        void setCPY(double value) { CPY = value; }
        void getDistance() override {
            Distance = sqrt(pow(centPointX - 0, 2) + pow(CPY - 0, 2));
            cout << "Distance is: " << Distance << endl;
        }
        double getDistanceValue() override { return Distance; }
        void getArea() override {
            
            Area = (3.14 * (radius1 * radius2));
            cout << "Oval Area: " << Area << endl;   
       }
        double getAreaValue() override { return Area; }

    };

    class Square : public Shapes {
    private:
        double Area;
        double centPointX;
        double CPY;
        double Distance;
    protected:
        double side1;
        int getType() override { return type3; }
        void save(ofstream& file) override {
            file << type3 << endl;
            file << side1 << endl;
            file << Area << endl;
        }

        void load(ifstream& file) override {
            file >> Area;
        }
    public:
        Square() : Shapes() { side1 = 0; }
        Square(double centPointX, double CPY, double side1) { this->side1 = side1; this->centPointX = centPointX; this->CPY = CPY; }
        double getSide1() const { return side1; }
        void setSide1(double value) { side1 = value; }
        double getCP() override {
            cout << "CP: (" << centPointX << "," << CPY << ")" << endl;
            return centPointX;
        }
        void setCPX(double value) { centPointX = value; }
        void setCPY(double value) { CPY = value; }
        void getDistance() override {
            Distance = sqrt(pow(centPointX - 0, 2) + pow(CPY - 0, 2));
            cout << "Distance is: " << Distance << endl;
        }
        double getDistanceValue() override { return Distance; }
        void getArea() override {
            Area = (side1 * side1);
            
            cout << "Square Area: " << Area << endl;
            
            
        }
        double getAreaValue() override { return Area; }
        

    };

    class Rectangle : public Square {
    private:
        double side2;
        double Area;
        double centPointX;
        double CPY;
        double Distance;
    protected:
        virtual int getType() override { return type4; }
        virtual void save(ofstream& file) override {
            file << type4 << endl;
            file << getSide1() << endl;
            file << side2 << endl;
            file << Area << endl;
        }
        virtual void load(ifstream& file) override {
            int tempx;
            file >> tempx;
            setSide1(tempx);
            file >> side2;
            file >> Area;
        }
    public:
        Rectangle() : Square() { side2 = 0; }
        Rectangle(double centPointX, double CPY, double side2, int side1) : Square(centPointX, CPY, side1) { this->side2 = side2; this->centPointX = centPointX; this->CPY = CPY; }
        double getSide2() const { return side2; }
        void setSide2(double value) { side2 = value; }
        double getCP() override {
            cout << "CP: (" << centPointX << "," << CPY << ")" << endl;
            return centPointX;
        }
        void setCPX(double value) { centPointX = value; }
        void setCPY(double value) { CPY = value; }
        void getDistance() override {
            Distance = sqrt(pow(centPointX - 0, 2) + pow(CPY - 0, 2));
            cout << "Distance is: " << Distance << endl;
        }
        double getDistanceValue() override { return Distance; }
        void getArea() override {
            Area = (side1 * side2);
            cout << "Rectangle Area: " << Area << endl;
            
        }
        double getAreaValue() override { return Area; }
    };

    class Triangle : public Shapes {
    private:
        double height;
        double Area;
        double centPointX;
        double CPY;
        double Distance;
    protected:
        int getType() override { return type5; }
        void save(ofstream& file) override {
            file << type5 << endl;
            file << height << endl;
            file << Area << endl;
        }

        void load(ifstream& file) override {
            file >> Area;
        }
    public:
        Triangle() : Shapes() { height = 0; }
        Triangle(double centPointX, double CPY, double height) { this->height = height; this->centPointX = centPointX; this->CPY = CPY; }
       
        double getHeight() const { return height; }
        void setHeight(double value) { height = value; }
        double getCP() override {
            cout << "CP: (" << centPointX << "," << CPY << ")" << endl;
            return centPointX;
        }
        void setCPX(double value) { centPointX = value; }
        void setCPY(double value) { CPY = value; }
        void getDistance() override {
            Distance = sqrt(pow(centPointX - 0, 2) + pow(CPY - 0, 2));
            cout << "Distance is: " << Distance << endl;
        }
        double getDistanceValue() override { return Distance; }
        void getArea() override {
            Area = ((height * height) / 2);
            cout << "Triangle Area: " << Area << endl;
            
            
        }
        double getAreaValue() override { return Area; }
        
    };

    Shapes* Shapes::readFromFile(ifstream& file) {
        int type = -1;
        file >> type;
        switch (type) {
        case type1: 
        {
            Shapes* temp = new Circle();
            temp->load(file);
            return temp;
        }
        case type2:
        {
            Shapes* temp = new Oval();
            temp->load(file);
            return temp;
        }
        case type3:
        {
            Shapes* temp = new Square();
            temp->load(file);
            return temp;
        }
        case type4:
        {
            Shapes* temp = new Rectangle();
            temp->load(file);
            return temp;
        }
        case type5:
        {
            Shapes* temp = new Triangle();
            temp->load(file);
            return temp;
        }
        }
        return nullptr;
    }
    void selectionSort(double [], int);
    void swap(double &, double &);
    void selectionSort2(double[], int);
    void swap2(double&, double&);
    

    int main()
    {
        int i;
        //declare dynamic array of objects
        Shapes** list = new Shapes *[5];
        int input2;
        for (int i = 0; i < 5;) {
            cout << "Choose a new shape to enter: " << endl;
            cout << "1 = Circle" << endl << "2 = Oval" << endl << "3 = Square" << endl << "4 = Rectangle" << endl << "5 = Triangle" << endl;
            cin >> input2;

            if (input2 == 1) {
                double r, x, y, i;
                
                cout << "What is your Circle's Radius?" << endl;
                cin >> r;
                cout << "What is your Circle's CenterPoint (x,y)?" << endl;
                cin >> x >> y;
                list[0] = new Circle(x, y, r);
                list[0]->getCP();
                list[0]->getDistance();
                list[0]->getArea();
                ofstream output("data.txt");
                list[0]->writeToFile(output);
                output.close();
            }

            else if (input2 == 2) {
                int r1, r2, x, y, i;
                cout << "What is your Oval's Major Radius?" << endl;
                cin >> r1;
                cout << "What is your Oval's Minor Radius?" << endl;
                cin >> r2;
                cout << "What is your Circle's CenterPoint (x,y)?" << endl;
                cin >> x >> y;
                list[1] = new Oval(x, y, r1, r2);
                list[1]->getCP();
                list[1]->getDistance();
                list[1]->getArea();
                ofstream output("data.txt");
                list[1]->writeToFile(output);
                output.close();

            }

            else if (input2 == 3) {
                double s, x, y, i;
                cout << "What is your Square's Side?" << endl;
                cin >> s;
                cout << "What is your Circle's CenterPoint (x,y)?" << endl;
                cin >> x >> y;
                list[2] = new Square(x, y, s);
                list[2]->getCP();
                list[2]->getDistance();
                list[2]->getArea();
                ofstream output("data.txt");
                list[2]->writeToFile(output);
                output.close();

            }

            else if (input2 == 4) {
                int s1, s2, x, y, i;
                cout << "What is your Rectangle's Length and Width?" << endl;
                cin >> s1 >> s2;
                cout << "What is your Rectangle's CenterPoint (x,y)?" << endl;
                cin >> x >> y;
                list[3] = new Rectangle(x, y, s1, s2);
                list[3]->getCP();
                list[3]->getDistance();
                list[3]->getArea();
                ofstream output("data.txt");
                list[3]->writeToFile(output);
                output.close();
            }

            else if (input2 == 5) {
                double h, x, y, i;
                cout << "What is your Triangle's Height?" << endl;
                cin >> h;
                cout << "What is your Triangle's CenterPoint (x,y)?" << endl;
                cin >> x >> y;
                list[4] = new Triangle(h, x, y);
                list[4]->getCP();
                list[4]->getDistance();
                list[4]->getArea();
                ofstream output("data.txt");
                list[4]->writeToFile(output);
                output.close();
            }
            i++;
        }

        double* area;
        area = new double[5];
        for (int i = 0; i < 5; i++) {
            double a = list[i]->getAreaValue();
            area[i] = a; 
        }
       
        double* distance;
        distance = new double[5];

        for (int i = 0; i < 5; i++) {
            double d = list[i]->getDistanceValue();
            distance[i] = d;
        }

        //choose how to sort
        cout << " How would you like to sort your shapes by: " << endl << "1) area" << endl << "2) distance" << endl;
        cin >> i;
        if (i == 1) {
            selectionSort(area, 5);
            cout << "Sorted shapes by area: " << endl;
            for (int i = 0; i < 5; i++) {
                cout << area[i] << endl;
            }
        }
        else if (i == 2) {
            selectionSort2(distance, 5);
            cout << "Sorted shapes by distance: " << endl;
            for (int i = 0; i < 5; i++) {
                cout << distance[i] << endl;
            }
        }

        //delete memory allocated
        delete[] list;
        delete[] area;
        delete[] distance;

        //read from file
        Shapes* arr[5];
        ifstream input("data.txt");
        for (int i = 0; i < 5; i++) {
            arr[i] = Shapes::readFromFile(input);
        }

        
    
    system("pause");
    return 0;

}


void selectionSort(double area[], int size)
{

    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++) {

        minIndex = start;
        minValue = area[start];
        for (int index = start + 1; index < size; index++) {

            
            if (area[index] < minValue) {
                
                minValue = area[index];
                minIndex = index;
            }
        }
        swap(area[minIndex], area[start]);
    }
}

void swap(double &a, double &b) {
    int temp = a;
    a = b;
    b = temp;
} 

void selectionSort2(double distance[], int size)
{

    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++) {

        minIndex = start;
        minValue = distance[start];
        for (int index = start + 1; index < size; index++) {
            
            if (distance[index] < minValue) {
                minValue = distance[index];
                minIndex = index;
            }
        }
        swap(distance[minIndex], distance[start]);
    }
}

void swap2(double& a, double& b) {
    int temp = a;
    a = b;
    b = temp;
}
