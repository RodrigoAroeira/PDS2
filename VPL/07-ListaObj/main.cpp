#include <cstdlib>
#include <iostream>
#include <list>
#include <memory>

#define DISPLAY_ERRO std::cerr << "ERRO" << std::endl

enum class Opt {

  AUTO = 'A',
  CREATE = 'C',
  REMOVE = 'R',
  NUMBER = 'N',
  PRINT = 'P',
  LIST = 'L',
  END = 'E',

};

class Obj {
public:
  static int count;
  static int currAutoID;

  Obj() : mID(currAutoID++) { count++; }
  explicit Obj(int id) : mID(id) { count++; }

  int getID() const { return mID; }

  ~Obj() {
    count--;
    if (count < 0)
      count = 0;
  }

  friend std::ostream &operator<<(std::ostream &os, const Obj &obj) {
    os << obj.getID() << " " << &obj;
    return os;
  }

private:
  int mID;
};

int Obj::count = 0;
int Obj::currAutoID = 1;

int main() {
  char opt;
  std::list<std::unique_ptr<Obj>> list;

  bool running = true;
  while (running) {
    std::cin >> opt;

    switch (static_cast<Opt>(opt)) {
    case Opt::AUTO: {
      std::unique_ptr<Obj> obj(new Obj);
      std::cout << *obj << std::endl;
      list.push_back(std::move(obj));
    } break;

    case Opt::CREATE: {
      int id;
      std::cin >> id;
      if (id >= 0) {
        DISPLAY_ERRO;
        continue;
      }
      std::unique_ptr<Obj> obj(new Obj(id));
      std::cout << *obj << std::endl;
      list.push_front(std::move(obj));
    } break;

    case Opt::REMOVE: {
      if (list.empty()) {
        DISPLAY_ERRO;
        continue;
      }
      std::cout << *list.front() << std::endl;
      list.pop_front();
    } break;

    case Opt::NUMBER: {
      std::cout << Obj::count << std::endl;
    } break;

    case Opt::PRINT: {
      int pos;
      std::cin >> pos;
      if (pos >= 1 && pos <= (int)list.size()) {
        auto it = std::next(list.begin(), pos - 1);
        Obj *tmp = (*it).get();
        std::cout << *tmp << std::endl;
      } else {
        DISPLAY_ERRO;
      }
    } break;

    case Opt::LIST: {
      if (list.empty()) {
        DISPLAY_ERRO;
        continue;
      }
      for (auto &obj : list) {
        std::cout << *obj << std::endl;
      }
    } break;

    case Opt::END:
      running = false;
      break;

    default:
      std::cerr << "Opção inválida." << std::endl;
      break;
    }
  }
}
