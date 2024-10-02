package animals;

public class Tier {

	String name;
	int maxAlter;

	public Tier(String name, int maxAlter) {

		this.name = name;
		this.maxAlter = maxAlter;

	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getMaxAlter() {
		return maxAlter;
	}

	public void setMaxAlter(int maxAlter) {
		this.maxAlter = maxAlter;
	}

}
