#include <cstdio>
#include <memory>
#include <utility>

struct Person;

struct Team {
  // potentially and array/vector
  std::shared_ptr<Person> members{};

  ~Team() { puts("~Team"); }
};

struct Person {
  std::weak_ptr<Team> team{};

  ~Person() { puts("~Person"); }
};

void Fun()
{
  auto teamWoods = std::make_shared<Team>();
  auto alex      = std::make_shared<Person>();

  teamWoods->members = alex;
  alex->team         = teamWoods;
}

int main()
{
  Fun();
  puts("finished");
}