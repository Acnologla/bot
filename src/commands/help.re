open CommandRegister
open Discord
let register = commands => {
  name: ["help"],
  description: "Help",
  run: (message, _) => {
    let args = Args.parse(message.content)
    switch (Array.length(args)) {
    | 0 =>
      Embed.(
        create()
        |> title("help")
        |> footer({
             text: {j|use j!help <comando> para ver mais informaçoes sobre um comando |j},
           })
        |> description(
             List.map(
               (command: command) => "`" ++ List.hd(command.name) ++ "`",
               commands,
             )
             |> String.concat(", "),
           )
        |> toEmbed
        |> Message.reply(message)
      )
    | _ =>
      switch (findCommand(args[0], commands)) {
      | command =>
        Embed.(
          create()
          |> title(args[0])
          |> description(command.description)
          |> toEmbed
          |> Message.reply(message)
        )
      | exception Not_found =>
        Message.reply(message, toStr("Não achei esse comando"))
      }
    }
  }
}
