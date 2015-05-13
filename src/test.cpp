#include <bandit/bandit.h>

using namespace bandit;

go_bandit([](){
    describe("fuzzbox:", [](){
      int a = 1;

      before_each([&](){
        a = 2;
      });

      it("starts in clean mode", [&](){
        AssertThat(a+2, Equals(4));
      });

//       describe("in distorted mode", [&](){
//         before_each([&](){
//           fuzzbox->flip();
//         });
//
//         it("sounds distorted", [&](){
//           AssertThat(guitar->sound(), Equals(sounds::distorted));
//         });
//       });
    });
});

int main(int argc, char* argv[])
{
  return bandit::run(argc, argv);
}
