const unsigned short int VANCOUVER = 0
const unsigned short int EDMONTON = 1
const unsigned short int CALGARY = 2
const unsigned short int SASKATOON = 3
const unsigned short int REGINA = 4
const unsigned short int WINNIPEG = 5
const unsigned short int THUNDERBAY = 6
const unsigned short int SUDBURY = 7
const unsigned short int KITCHENER = 8
const unsigned short int HAMILTON = 9
const unsigned short int TORONTO = 10
const unsigned short int BARRIE = 11
const unsigned short int OSHAWA = 12
const unsigned short int PETERBOROUGH = 13
const unsigned short int KINGSTON = 14
const unsigned short int OTTAWA = 15
const unsigned short int MONTREAL = 16
const unsigned short int SHERBROOK = 17
const unsigned short int QUEBEC = 18
const unsigned short int SAINTJOHN = 19
const unsigned short int MONCTON = 20
const unsigned short int HALIFAX = 21
const unsigned short int CAPEBRETON = 22

const float COORD[23][2] = {{49.2612, -123.1139}, // VANCOUVER
                            {53.5445, -113.4910}, // EDMONTON
                            {51.0454, -114.0581}, // CALGARY
                            {52.1344, -106.6477}, // SASKATOON
                            {, }, // REGINA
                            {, }, // WINNIPEG
                            {, }, // THUNDERBAY
                            {, }, // SUDBURY
                            {, }, // KITCHENER
                            {, }, // HAMILTON
                            {, }, // TORONTO
                            {, }, // BARRIE
                            {, }, // OSHAWA
                            {, }, // PETERBOROUGH
                            {, }, // KINGSTON
                            {, }, // OTTAWA
                            {, }, // MONTREAL
                            {, }, // SHERBROOK
                            {, }, // QUEBEC
                            {, }, // SAINTJOHN
                            {, }, // MONCTON
                            {, }, // HALIFAX
                            {, }} // CAPEBRETON

const short int ME = -1
const short int UP = 0
const short int DOWN = 1
const short int DISCONNECTED = 2

template <class T>
class Link {
public:
    Link(T* data) {
        this->data = data;
    }

    T* data;
    Link* next;
    Link* prev;
};

class Stack {
    Stack() {
        front = NULL;
    }

    ~Stack() {
        while (front->next != NULL) {
            front = front->next;
            delete front->prev;
        }
        delete front; // Delete final node
    }

    T* peak() {
        return front->data;
    }

    T* push(T* data) {
        Link* tmp = new Link(data);
        tmp->next = front;
        tmp->prev = NULL;

        front->prev = tmp;
        front = tmp;

        return data;
    }

    T* pop() {
        T* ret = front->data;

        front = front->next;
        delete front->prev;
        front->prev = NULL;

        return ret;
    }

protected:
    Link* front;
};

class Que : Stack { // Que is pretty much a stack except for how it pushes
    T* push(T* data) {
        Link* tmp = new Link(data);
        tmp->next = NULL;

        tmp->prev = front; // Put the new link after the first
        while (tmp->prev->next != NULL) // While the node isn't at the end
            tmp->prev = tmp->prev->next; // Shift it right
        tmp->prev->next = tmp; // Point the now second last node at the new one

        return data;
    }
};

class GraphNode {
    GraphNode(T* data) {
        this->data = data;
        linkCount = 0;
    }

    ~GraphNode() {
        while (linkCount != 0)
            delete link[--linkCount];
    }

    GraphNode* addChild(T* child) {
        GarphNode[linkCount++] = new GraphNode(T*);
    }

    GraphNode** link;
    T* data;
    unsigned short int linkCount;
};

class Router{
    Router(unsigned short int routerName) {
        linkTo = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2} // All routers are dissconnected
        linkTo[routerName] = -1; // I am me... Duh!
        links = new GraphNode(this);
    }

    // All these change both sides of link
    bool addLink(Router* router);
    bool dropLink(Router* router);
    bool upLink(Router* router);
    bool downLink(Router* router);

    float distTo(unsigned short int routerName);
    unsigned short int name();

    GraphNode* spf();
    GraphNode* bellman();
    GraphNode* kruskal();
    GraphNode* prim();
    Link* aStar(Router* destRouter);

    short int linkTo[23];
    GraphNode* links;
};