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

## TODO — `Scale` class follow-ups

Best-practice cleanups identified during review but not yet applied
(tracked here rather than changed in code). Update the class diagram once
these land.

- **Encapsulate the HX711.** Own it by value as a member instead of taking
  a non-owning `HX711*`. `Scale` is its only consumer, so the pointer also
  lets the global `HX711` and the sensor dependency leak into `main.cpp`.
- **Rename `initializeScale()` → `initialize()`** — the `Scale` suffix is
  redundant on a method of `Scale`.
- **`readData()` → `readGrams()` returning `float`.** Return the reading
  directly instead of writing it to a public field as a side effect.
- **Drop the public `sensorData` field** (bad name, and it's mutable public
  state only `DispenserController` reads — made redundant by `readGrams()`).
- **Remove the blocking `delay(100)` from the read path.** Baking a 100 ms
  delay into a getter couples loop timing into the data path; let the caller
  pace, or document why the settle delay belongs there.
- **Use a constructor member-initializer list** instead of assigning members
  in the body.
- **Add a timeout to the `while (!is_ready())` wait** in init so a
  disconnected/faulty load cell can't hang startup forever, and let init
  report success/failure instead of returning `void`.
- **Average multiple samples** for a stable reading (`get_units(times)`)
  rather than a single sample.
- **Explain or remove the throwaway `read()`** in init (its result is
  discarded — warm-up/flush?).
- **Consider merging `begin()` and `initialize()`** — they're always called
  back-to-back and nowhere else (Arduino convention is a single `begin()`).
- **Make member naming consistent** — `DTPin`/`SCKPin` vs `calibrationFactor`
  mix conventions.
- **Name the magic numbers** — the `1000 ms` poll interval and `100 ms`
  settle delay.
- **Document the unit assumption** — `get_units()` only returns grams if
  `calibrationFactor` is calibrated to grams.
