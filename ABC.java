abstract class Writer {
	abstract void write();
}

class Pen extends Writer {
	void write() {
		System.out.println("Written by pen ");
	}
}

class Pencil extends Writer {
	void write() {
		System.out.println("Written by pencil ");
	}
}

class Exam {
	void solve(Writer w) {
		w.write();
	}
}

class ABC {
	public static void main(String[] args) {
		Pen penobj = new Pen();
		Pencil pencilobj = new Pencil();

		Exam obj = new Exam();
		obj.solve(penobj);
	}
}