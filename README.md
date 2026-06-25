# Dispenser

Code for the first revision dispenser assembly.

A weight-triggered pneumatic dispenser built on an ESP32 (PlatformIO /
Arduino framework). An HX711 load cell drives the control loop: when the
measured weight crosses a threshold, `DispenserController` extends the
pneumatic piston, lights the indicator LED, and re-tares the scale.

## Architecture

![Class diagram](diagrams/class-diagram.png)

The diagram source is [`diagrams/class-diagram.mmd`](diagrams/class-diagram.mmd)
(Mermaid). Regenerate the image after editing it with:

```sh
mmdc -i diagrams/class-diagram.mmd -o diagrams/class-diagram.png
```
