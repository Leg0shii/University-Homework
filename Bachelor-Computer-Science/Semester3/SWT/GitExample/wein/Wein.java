package testworld.wein;

public class Wein {

	String name;
	String farbe;
	int alter; //Jahreszahl

	public Wein(Wein wein) {

		this.name = wein.name;
		this.alter = wein.alter;
		this.farbe = wein.farbe;

	}

	public Wein(String name, String farbe, int alter) {

		this.name = name;
		this.farbe = farbe;
		this.alter = alter;

	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getFarbe() {
		return farbe;
	}

	public void setFarbe(String farbe) {
		this.farbe = farbe;
	}

	public int getAlter() {
		return alter;
	}

	public void setAlter(int alter) {
		this.alter = alter;
	}
}
