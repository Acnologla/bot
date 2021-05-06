open Discord
open Message
open CommandRegister

Dotenv.config()
[@bs.val] external token: string = "process.env.TOKEN"
[@bs.val] external prefix: string = "process.env.PREFIX"
let prefixLen = String.length(prefix)

let client = Client.create()

let commands =
  []
  |> registerCommand(Ping.register())
  |> registerCommand(Avatar.register())
  |> registerCommand(Escrever.register())
  |> registerCommand(GuildIcon.register())

let commands = registerCommand(Help.register(commands), commands)
let callback = message =>
  if (Js.String.startsWith(prefix, message.content)) {
    let commandName = (
                        String.sub(
                          message.content,
                          prefixLen,
                          String.length(message.content) - prefixLen,
                        )
                        |> Js.String.split(" ")
                      )[0]
    switch (findCommand(commandName, commands)) {
    | command => command.run(message, client)
    | exception Not_found => ()
    }
  }

Client.onMessage(client, callback)
Client.onReady(client, () => Js.log(client.user.tag))
Client.login(client, token)
