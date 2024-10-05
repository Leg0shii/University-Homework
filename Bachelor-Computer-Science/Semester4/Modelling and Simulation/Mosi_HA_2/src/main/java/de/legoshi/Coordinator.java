package de.legoshi;

import de.legoshi.util.Message;
import de.legoshi.util.MessageType;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Coordinator {

    private Coordinator parent;
    private Simulator[] childSim;
    private Coordinator[] childCoord;
    private int time;

    public Coordinator(Coordinator parent) {
        this.parent = parent;
    }

    public void receiveMessage(Message message) {

        if(message.getMessageType().equals(MessageType.STAR)) {
            for(Simulator simulator : childSim) {
                if(simulator.getTonie() == message.getTime()) {
                    simulator.receiveMessage(message);
                }
            }
            for(Coordinator coordinator : childCoord) {
                coordinator.receiveMessage(message);
            }
        } else if(message.getMessageType().equals(MessageType.X)) {
            for(Simulator simulator : childSim) {
                simulator.receiveMessage(message);
            }

        } else if(message.getMessageType().equals(MessageType.Y)) {

            if(parent != null) {
                for(Simulator simulator : childSim) {
                    if(!simulator.equals(message.getSender())) {
                        simulator.receiveMessage(message);
                    }
                }
                message.setSender(this);
            }

        }
    }

    public void sendMessage(Message message) {

    }

}
