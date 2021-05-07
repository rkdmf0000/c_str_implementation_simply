#include <iostream>


class _spare_string {

public:
    static void print_log(float value) {
        _spare_string::print_log((const unsigned char*)(int)value);
    };
    static void print_log(double value) {
        _spare_string::print_log((const unsigned char*)(int)value);
    };
    static void print_log(unsigned int value) {
        _spare_string::print_log((const unsigned char*)value);
    };
    static void print_log(int value) {
        _spare_string::print_log((const unsigned char*)value);
    };
    static void print_log(const char* value) {
        _spare_string::print_log((unsigned char*)value);
    };
    static void print_log(const unsigned char* value) {
        printf("- - - - %s\n",value);
    };

    _spare_string(void) {
        this->_init();
        this->_after_init();
    };
    _spare_string(unsigned char* txt) {
        this->_init();
        this->saver = txt;
        this->size = this->_get_size_for_str();
        this->_after_init();
    };
    ~_spare_string() {
        _spare_string::print_log("destroyed spare_string class");
        delete this->saver;
    };


    const unsigned char* c_str(void) {
        return this->saver;
    };
private:
    unsigned char* saver;
    unsigned int size;
private:
    void _init(void) {
        _spare_string::print_log("born a spare_string class");
        this->saver = nullptr;
    };
    void _after_init(void) {
        _spare_string::print_log("after sets");
        std::cout << this->saver << '\n';
        std::cout << this->size << '\n';
    };
    const unsigned int _get_size_for_str() {
        unsigned int i(0);
        while(this->saver[i])
            ++i;
        return i;
    };
};


int main() {

    _spare_string fx((unsigned char*)"hello_world!"); //probably it'll returns rvalue

    std::cout << "c_str returns : " << fx.c_str() << '\n';

    std::cout << "is program's over" << '\n';
    return 0;
}
