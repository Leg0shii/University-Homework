package testworld;

public class BenjaminsKlasse {

	String name;
	int alter;
	String nachricht;

	public BenjaminsKlasse(String name, int alter, String nachricht) {

		this.name = name;
		this.alter = alter;
		this.nachricht = nachricht;

	}

	public void sagNamen() {

		System.out.println(nachricht);

	}

}
