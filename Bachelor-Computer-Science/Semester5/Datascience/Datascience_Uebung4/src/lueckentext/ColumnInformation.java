package lueckentext;

public class ColumnInformation {

	int position;
	String name;
	String type;
	long size;
	
	public ColumnInformation(int position, String name, String type, long size) {
		super();
		this.position = position;
		this.name = name;
		this.type = type;
		this.size = size;
	}

	public int getPosition() {
		return position;
	}

	public void setPosition(int position) {
		this.position = position;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public long getSize() {
		return size;
	}

	public void setSize(long size) {
		this.size = size;
	}
	
	@Override
	public String toString() {
		return "(Pos: " + position + ", Name: "+ name + ", Type: " + type + ", Size: " + size + ")";
		
	}
}
