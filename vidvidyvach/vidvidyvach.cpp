#include <iostream>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;

// Visitor
class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA* elementA) = 0;
    virtual void visitConcreteElementB(ConcreteElementB* elementB) = 0;
};

// Element
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

// ConcreteElementA
class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementA(this);
    }

    void operationA() {
        std::cout << "ConcreteElementA operationA" << std::endl;
    }
};

// ConcreteElementB
class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementB(this);
    }

    void operationB() {
        std::cout << "ConcreteElementB operationB" << std::endl;
    }
};

// ConcreteVisitorA
class ConcreteVisitorA : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* elementA) override {
        std::cout << "ConcreteVisitorA visits ConcreteElementA" << std::endl;
        elementA->operationA();
    }

    void visitConcreteElementB(ConcreteElementB* elementB) override {
        std::cout << "ConcreteVisitorA visits ConcreteElementB" << std::endl;
        elementB->operationB();
    }
};

// ConcreteVisitorB
class ConcreteVisitorB : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* elementA) override {
        std::cout << "ConcreteVisitorB visits ConcreteElementA" << std::endl;
        elementA->operationA();
    }

    void visitConcreteElementB(ConcreteElementB* elementB) override {
        std::cout << "ConcreteVisitorB visits ConcreteElementB" << std::endl;
        elementB->operationB();
    }
};

// ObjectStructure
class ObjectStructure {
private:
    std::vector<Element*> elements;

public:
    void addElement(Element* element) {
        elements.push_back(element);
    }

    void accept(Visitor* visitor) {
        for (Element* element : elements) {
            element->accept(visitor);
        }
    }
};

int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ObjectStructure objectStructure;
    objectStructure.addElement(&elementA);
    objectStructure.addElement(&elementB);

    ConcreteVisitorA visitorA;
    ConcreteVisitorB visitorB;

    std::cout << "Visiting elements with ConcreteVisitorA:" << std::endl;
    objectStructure.accept(&visitorA);

    std::cout << "\nVisiting elements with ConcreteVisitorB:" << std::endl;
    objectStructure.accept(&visitorB);

    return 0;
}
