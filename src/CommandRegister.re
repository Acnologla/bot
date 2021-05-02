open Discord
type command = {
    name: list(string),
    run: (Message.t, Client.t) => unit
}

let registerCommand = (command, commands) => [command, ...commands]