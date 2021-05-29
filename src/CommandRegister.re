open Discord

let (>>|) = (opt, func) => {
  switch(opt){
  | Some(x) => {
    func(x)
    None
  }
  | None => None
  }
};

type command = {
  name: list(string),
  description: string,
  run: (Message.t, Client.t) => unit,
}

let findCommand = (commandName, commands) => {
  List.find(
    command =>
      switch (
        List.find(
          aliase => aliase == String.lowercase_ascii(commandName),
          command.name
        )
      ) {
      | exception Not_found => false
      | _ => true
      },
    commands
  )
}

let registerCommand = (command, commands) => [command, ...commands]
