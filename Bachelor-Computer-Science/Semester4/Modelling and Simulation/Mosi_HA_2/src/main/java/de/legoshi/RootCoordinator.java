package de.legoshi;

import de.legoshi.util.Message;
import de.legoshi.util.MessageType;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class RootCoordinator extends Coordinator {

    public RootCoordinator() {
        super(null);
    }

    public void sendStarMessage() {

        Message StarMessage = new Message(MessageType.STAR, this, 0);

        for(Coordinator coordinator : this.getChildCoord()) {
            coordinator.receiveMessage(StarMessage);
        }

        for(Simulator simulator : this.getChildSim()) {
            if(simulator.getTonie() == this.getTime()) {
                simulator.receiveMessage(StarMessage);
            }
        }
    }

}
