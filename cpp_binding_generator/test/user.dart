import 'package:cpp_binding/cpp_binding.dart';

@binding
class User {
  final Status status;

  User(this.status);

  Status fakeStatus(int n) {
    return new Status('fake$n');
  }

  int multiply(int x, {int loop: 2}) {
    var sum = 0;

    for (int i = 0; i < loop; i++) {
      sum += x;
    }

    return sum;
  }

  void sayHi() {
    print('Hello!');
  }
}

@binding
class Status {
  final String text;

  Status(this.text);
}
