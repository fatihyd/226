#include <iostream>

using namespace std;
// represents a node in a linked list
struct nodeType {
    int info;
    nodeType* link;
};

nodeType* buildListForward() {
    // first is necessary to keep track of the whole list
    // newNode is necessary to add new nodes
    // last is necessary to add new nodes at the end
    nodeType* first;
    nodeType* newNode;
    nodeType* last;
    int num;

    cout << "Enter a list of integers ending with -999.\n";
    /*
     * we HAVE TO get the first input outside the loop
     * to be able to set the first to NULL
     */
    cin >> num;
    first = NULL; // represents that the "list" is empty

    while (num != -999) {
        newNode = new nodeType;

        newNode->info = num;
        /*
         * last node in the list needs to have a NULL link
         * to represent the end of the list
         */
        newNode->link = NULL;
        // runs only for the first loop
        if (first == NULL) {
            first = newNode; // sets the first (and only) node
            last = newNode; // sets the last (and only) node
        } else {
            last->link = newNode; // adds the new node to the end of the list
            last = newNode; // sets the last node
        }

        cin >> num;
    }
    return first;
}

nodeType* buildListBackward() {
    /*
     * 'last' is not necessary
     * since new nodes are linked
     * to 'first' in reverse
     */
    nodeType* first;
    nodeType* newNode;
    int num;

    cout << "Enter a list of integers ending with -999." << endl;
    cin >> num;
    first = NULL; // ???

    while (num != -999) {
        newNode = new nodeType;
        newNode->info = num;
        /*
         * the 'link' field of the new node is set to the current first node of the list
         * this effectively inserts the new node at the beginning of the list
         */
        newNode->link = first;
        // update 'first' to point to the new node, which is the new first node of the list
        first = newNode;
        cin >> num;
    }
    return first;
}

void print(nodeType *current) {
    cout << " Printing linked list: ";
    while (current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

int main() {
    //nodeType *node = buildListForward();
    nodeType* node = buildListBackward();
    print(node);
    cout << "first:" << node->info;
}

