using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Panel único de contenido: muestra las content_sections de un topic (obtenidas de la BD)
/// y permite navegar entre ellas con Next()/Prev(). Se abre desde los eyebuttons del
/// modelo 3D (ver ARPartButtonManager) pasando el id_topic correspondiente a la parte.
/// </summary>
public class TopicContentPanel : MonoBehaviour
{
    [Header("Panel")]
    public GameObject panelRoot;
    public GameObject buttonsRoot;

    [Header("Textos")]
    public TextMeshProUGUI topicNameText;
    public TextMeshProUGUI sectionTitleText;
    public TextMeshProUGUI sectionTypeText;
    public TextMeshProUGUI bodyText;

    [Header("Botones")]
    public Button nextButton;
    public Button prevButton;
    public Button closeButton;

    private TopicsRepository _repository;
    private List<SeccionJson> _sections = new List<SeccionJson>();
    private int _currentIndex;
    private int _currentTopicId = -1;

    public bool IsOpen => panelRoot != null && panelRoot.activeSelf;
    public int CurrentTopicId => _currentTopicId;

    // Se dispara al cerrar el panel (boton Close o toggle-close desde un
    // eyebutton), para que quien enfoco/ilumino una parte pueda revertirlo.
    public System.Action OnClosed;


    void Awake()
    {
        _repository = new TopicsRepository();

        if (nextButton != null) nextButton.onClick.AddListener(Next);
        if (prevButton != null) prevButton.onClick.AddListener(Prev);
        if (closeButton != null) closeButton.onClick.AddListener(Close);

        Close();
    }

    public void ShowTopic(int idTopic)
    {
        if (_currentTopicId == idTopic && panelRoot != null && panelRoot.activeSelf)
        {
            Close();
            return;
        }

        TopicModel topic = _repository.GetTopicById(idTopic);
        _sections = _repository.GetSections(idTopic);
        _currentIndex = 0;
        _currentTopicId = idTopic;

        if (_sections.Count == 0)
        {
            Debug.LogWarning($"[TopicContentPanel] El topic {idTopic} no tiene content_sections.");
            return;
        }

        if (topicNameText != null) topicNameText.text = topic != null ? topic.name : string.Empty;

        if (panelRoot != null) panelRoot.SetActive(true);
        if (buttonsRoot != null) buttonsRoot.SetActive(true);

        RenderCurrentSection();
    }

    public void Next()
    {
        if (_currentIndex >= _sections.Count - 1) return;

        _currentIndex++;
        RenderCurrentSection();
    }

    public void Prev()
    {
        if (_currentIndex <= 0) return;

        _currentIndex--;
        RenderCurrentSection();
    }

    public void Close()
    {
        _currentTopicId = -1;

        if (panelRoot != null) panelRoot.SetActive(false);
        if (buttonsRoot != null) buttonsRoot.SetActive(false);

        OnClosed?.Invoke();
    }

    void RenderCurrentSection()
    {
        SeccionJson section = _sections[_currentIndex];

        if (sectionTitleText != null) sectionTitleText.text = section.title;
        if (sectionTypeText != null) sectionTypeText.text = section.section_type;
        if (bodyText != null) bodyText.text = section.content;

        if (prevButton != null) prevButton.interactable = _currentIndex > 0;
        if (nextButton != null) nextButton.interactable = _currentIndex < _sections.Count - 1;
    }
}
