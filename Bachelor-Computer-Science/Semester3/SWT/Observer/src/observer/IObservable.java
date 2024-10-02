package observer;

public interface IObservable {

	void add(IObserver iObserver);
	void  remove(IObserver iObserver);
	void _notify();

}
